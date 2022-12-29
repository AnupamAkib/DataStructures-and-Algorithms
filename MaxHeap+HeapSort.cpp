#include <bits/stdc++.h>

using namespace std;

class MaxHeap{
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
			if(ar[cur] > ar[cur/2]){ 
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
				if(ar[leftChild] > ar[rightChild]){ //left child value greater
					if(ar[leftChild] > ar[node]){ //if left child is greater than current node, swap them
						swap(ar[leftChild], ar[node]);
						node = leftChild; //go to left child
					}
					else break; //it is already in correct place, so break the process
				}
				else{ //right child value greater/equal
					if(ar[rightChild] > ar[node]){ //if right child is greater than current node, swap them
						swap(ar[rightChild], ar[node]);
						node = rightChild; //go to right child
					}
					else break; //it is already in correct place, so break the process
				}
			}
			else if(leftChild < lastFreePosition){ //only left side inside complete binary tree
				if(ar[leftChild] > ar[node]){ //left child is greater than current node, swap them
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


int * HeapSort(int a[], int arraySize){ /* Time Complexity = O(NlogN) */
	MaxHeap heap; //we implement heap sort (in ascending order) using MaxHeap
	for(int i=0; i<arraySize; i++){ //at first, create a heap by inserting elements
		heap.Insert(a[i]);
	}
	for(int i=0; i<arraySize; i++){ //delete elements one by one
		heap.Delete();
	}
	for(int i=1; i<=arraySize; i++){ //elements was deleted from root and it kept is last position one by one. root always contain greater value. So, the remaining array in heap is the sorted array
		a[i-1] = heap.ar[i]; //store sorted array in current array
	}
	return a;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	MaxHeap heap; //declare a MaxHeap

	heap.Insert(15);
	heap.Insert(7);
	heap.Insert(7);
	heap.Insert(4);
	heap.Insert(14);
	heap.Insert(11);
	heap.Insert(10);

	heap.printTree();

	cout << heap.Top() << endl;

	heap.Insert(10);
	heap.Insert(1);

	heap.Delete();
	heap.Delete();
	heap.Delete();
	heap.Delete();

	heap.printTree();


	cout << endl;
	//sort array using heap sort
	int ar[] = {2, 3, 45, 1, 9, 10, 1000, 12, 8}; //array to be sorted
	int arraySize = 9; //array size to be sorted
	HeapSort(ar, arraySize); //call for sort
	for(int i=0; i<arraySize; i++){ //print the ascending order sorted array
		cout << ar[i] << " ";
	}
	cout << endl;

	//We can also implement 'Priority Queue' using this Heap data structure
	//for implementing MinHeap, just change some sign according to logic

	return 0;
}
