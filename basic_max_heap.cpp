// Basic Max Heap:
#include <iostream>
#include <limits.h>
using namespace std;


class MaxHeap
{
	int *arr;
	int maxHeapSize;
	int heapSize;
	
	public:
		MaxHeap(int size)
		{
			heapSize = 0;
			maxHeapSize = size;
			arr = new int[size];
		}
		
		void insertKey(int key); // insert a key in the heap
		void deleteKey(int index); // remove a key from a particular index
		
		int removeMax();
		int getMax();
		void maxHeapify(int index);
		
		int parent(int i);
		int lChild(int i);
		int rChild(int i);
		int currSize();
		void increaseKey(int i, int newVal);
};

// Get the parent of any node
int MaxHeap :: parent(int i)
{
	return ((i - 1) / 2);
}

//get left child 
int MaxHeap :: lChild(int i)
{
	return (2*i + 1);
}

// get right child
int MaxHeap :: rChild(int i)
{
	return (2*i + 2);
}
 
// current size of the heap
int MaxHeap :: currSize()
{
	return heapSize;
}

void MaxHeap :: increaseKey(int i, int newVal)
{
	arr[i] = newVal;
	while (i != 0 && arr[i] > arr[parent(i)])
	{
		swap(arr[i], arr[parent(i)]);
		i = parent(i);
	}
	
}

void MaxHeap :: insertKey(int key)
{
	if(heapSize == maxHeapSize)
	{
		cout << "overflow. Can not insert another key";
		return;
	}
	heapSize++;
	int i = heapSize - 1;
	arr[i] = key;
	
	while(i != 0 && arr[i] > arr[parent(i)])
	{
		swap(arr[i], arr[parent(i)]);
		i = parent(i);
	}
}

void MaxHeap :: deleteKey(int index)
{
	increaseKey(index, INT_MAX);
	removeMax();
}

int MaxHeap :: removeMax()
{
	if(heapSize == 0)
		return INT_MIN;
	if(heapSize == 1)
	{
		heapSize --;
		return arr[0];
	}
		
	int root = arr[0];
	arr[0] = arr[heapSize - 1];
	heapSize--;
	maxHeapify(0);
	
	return root;
}

int MaxHeap :: getMax()
{
	return arr[0];
}

void MaxHeap :: maxHeapify(int i)
{
	int l = lChild(i);
	int r = rChild(i);
	int largest = i;
	
	if(l < heapSize && arr[l] > arr[i])
		largest = l;
	if(r < heapSize && arr[r] > arr[largest])
		largest = r;
	if(largest != i)
	{
		swap(arr[i], arr[largest]);
		maxHeapify(largest);
	}
}

int main() {
	
	// Assuming the maximum size of the heap to be 15.
    MaxHeap h(15);

    // Asking the user to input the keys:
    int k, i, n = 6, arr[10];
    cout << "Entered 6 keys:- 3, 10, 12, 8, 2, 14 \n";
    h.insertKey(3);
    h.insertKey(10);
    h.insertKey(12);
    h.insertKey(8);
    h.insertKey(2);
    h.insertKey(14);

    // Printing the current size
    // of the heap.
    cout << "The current size of the heap is "
         << h.currSize() << "\n";

    // Printing the root element which is
    // actually the maximum element.
    cout << "The current maximum element is " << h.getMax()
         << "\n";

    // Deleting key at index 2.
    h.deleteKey(2);

    // Printing the size of the heap
    // after deletion.
    cout << "The current size of the heap is "
         << h.currSize() << "\n";

    // Inserting 2 new keys into the heap.
    h.insertKey(15);
    h.insertKey(5);
    cout << "The current size of the heap is "
         << h.currSize() << "\n";
    cout << "The current maximum element is " << h.getMax()
         << "\n";
	return 0;
}


Output:

Entered 6 keys:- 3, 10, 12, 8, 2, 14 
The current size of the heap is 6
The current maximum element is 14
The current size of the heap is 5
The current size of the heap is 7
The current maximum element is 15
