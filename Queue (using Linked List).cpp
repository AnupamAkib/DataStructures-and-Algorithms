#include<bits/stdc++.h>
using namespace std;

class QueueNode{
public:
	int value;
	QueueNode *next;
	QueueNode(int _val){
		value = _val;
		next = nullptr;
	}
};

class Queue{ 
private:
	QueueNode *head, *tail;
	int queueSize;

public:
	Queue(){
		head = tail = nullptr;
		queueSize = 0;
	}

	bool Push(int val){
		if(tail == nullptr or head == nullptr){ //queue is empty
			tail = new QueueNode(val);
			head = tail;
		}
		else{
			tail -> next = new QueueNode(val);
			tail = tail -> next;
		}
		queueSize++;
		return true;
	}

	bool Pop(){
		if(queueSize && head != nullptr){
			QueueNode *tmp = head;
			head = head -> next;
			queueSize--;
			delete tmp; //delete the popped Node
			return true;
		}
		else{
			cerr << "Queue is Empty" << endl;
			return false;
		}
	}

	int Front(){
		if(queueSize && head != nullptr){
			return head -> value;
		}
		else{
			return INT_MIN; //front node doesn't exist
		}
	}

	int Length(){
		return queueSize;
	}

	void Display(){
		QueueNode *cur = head;
		while(cur != nullptr){
			cout << cur -> value << " ";
			cur = cur -> next;
		}
	}
};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Queue que; //declare the queue as que

	que.Push(7);
	que.Push(4);
	que.Pop();
	que.Push(10);
	que.Pop();
	que.Push(6);
	que.Push(2);
	que.Push(11);

	cout << "Queue Length = " << que.Length() << endl;
	cout << "Queue Front = " << que.Front() << endl;

	que.Display();

  /*
    // output:
    ----------------
    Queue Length = 4
    Queue Front = 10
    10 6 2 11 
    ----------------
  */
	
	return 0;
}
