#include <bits/stdc++.h>

using namespace std;

class MinHeap{
private:
	int lastFreePosition = 1; //We are making 1 indexed heap
	const static int MX_SIZE = 100000; //maximum heap size = 100000
public:
	int ar[MX_SIZE];

	void Insert(int value){ /* Time Complexity = O(logN) */
		if(lastFreePosition-1 == MX_SIZE){
			cout << "Heap Size Overflow!" << endl;
			return;
		}
		ar[lastFreePosition] = value; //insert the value at last free space.
		//now adjust the heap by comparing the inserted value with all it's ancestors.
		int cur = lastFreePosition; //compare last to root
		while(cur>1){
			//check with current node's parent
			if(ar[cur] < ar[cur/2]){ 
				swap(ar[cur], ar[cur/2]);
			}
			else break;
			cur /= 2; //go to it's parent node
		}
		lastFreePosition++; //now last position increased as 1 value inserted in heap
	}

	void Delete(){ /* Time Complexity = O(logN) */
		if(lastFreePosition == 1){
			cout << "Nothing to delete. Heap is empty!" << endl;
			return;
		}
		//in heap, we can delete only root element
		swap(ar[1], ar[lastFreePosition-1]); /*
		replace root with last. Later we will adjust the elements. 
		We swapped root with last element to keep track the root 
		element. We can use this in 'Heap Sort' */
		lastFreePosition--; //as 1 element has been deleted;
		//Now adjust the elements from root to last
		//This technique is called "HEAPIFY" for a heap
		int node = 1; //starting from root node
		while(1){ //HEAPIFY
			int leftChild = node*2;
			int rightChild = node*2 + 1;
			if(leftChild < lastFreePosition and rightChild < lastFreePosition){ //both child inside complete binary tree
				if(ar[leftChild] < ar[rightChild]){ //left child value smaller
					if(ar[leftChild] < ar[node]){ //if left child is less than current node, swap them
						swap(ar[leftChild], ar[node]);
						node = leftChild; //go to left child
					}
					else break; //it is already in correct place, so break the process
				}
				else{ //right child value greater/equal
					if(ar[rightChild] < ar[node]){ //if right child is less than current node, swap them
						swap(ar[rightChild], ar[node]);
						node = rightChild; //go to right child
					}
					else break; //it is already in correct place, so break the process
				}
			}
			else if(leftChild < lastFreePosition){ //only left side inside complete binary tree
				if(ar[leftChild] < ar[node]){ //left child is less than current node, swap them
					swap(ar[leftChild], ar[node]);
					node = leftChild; //go to left child
				}
				else break; //it is already in correct place, so break the process
			}
			else break; //we don't need to check only right side as only right side can't be present in a complete binary tree
		}
	}

	int Top(){ //it will return the maximum value in the heap
		int maxElement = ar[1]; //max value is in the root of the heap tree
		return maxElement;
	}

	void printTree(){ //print the array representation of the complete binary heap tree
		for(int i=1; i<lastFreePosition; i++){
			cout << ar[i] << " ";
		}
		cout << endl;
	}
};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	MinHeap heap; //declare a MinHeap

	heap.Insert(15);
	heap.Insert(7);
	heap.Insert(7);
	heap.Insert(4);
	heap.Insert(14);
	heap.Insert(11);
	heap.Insert(10);

	heap.printTree();

	cout << "Top = " << heap.Top() << endl;

	heap.Delete();

	heap.printTree();

	heap.Delete();

	heap.printTree();


	return 0;
}
