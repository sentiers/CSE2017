// CSE2017-01 Data Structure
// Lab 10 - Heap - inlab2
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 May 21
//
// heapsort.cpp
// :(Shell) heapSort() function


template < class DT >
void moveDown(DT dataItems[], int root, int size) {
	// Restores the binary tree that is rooted at root to a heap by moving
	// dataItem[root] downward until the tree satisfies the heap property.
	// Parameter size is the number of data items in the array.

	DT tempItem = dataItems[root];
	int child = 2 * root + 1;

	while (child < size) {
		if (child < size - 1 && dataItems[child].pty() < dataItems[child + 1].pty()) {
			child++;
		}
		if (tempItem.pty() < dataItems[child].pty()) {
			dataItems[root] = dataItems[child];
		}
		else {
			break;
		}
		root = child;
		child = 2 * root + 1;
	}
	dataItems[root] = tempItem;
}

//--------------------------------------------------------------------

template < class DT >
void heapSort(DT dataItems[], int size) {
	// Heap sort routine. Sorts the data items in the array in ascending
	// order based on priority.
	DT temp;   // Temporary storage
	int j;     // Loop counter

	// Build successively larger heaps within the array until the
	// entire array is a heap.
	for (j = (size - 1) / 2; j >= 0; j--)
		moveDown(dataItems, j, size);

	// Swap the root data item from each successively smaller heap with
	// the last unsorted data item in the array. Restore the heap after
	// each exchange.
	for (j = size - 1; j > 0; j--) {
		temp = dataItems[j];
		dataItems[j] = dataItems[0];
		dataItems[0] = temp;
		moveDown(dataItems, 0, j);
	}
}

