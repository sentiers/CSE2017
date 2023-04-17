// CSE2017-01 Data Structure
// Lab 10 - Heap - prelab
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 May 21
//
// heap.cpp
// :Actual implementation of class in the Heap ADT


#include "heap.h"
#include <iostream>

using namespace std;

//--------------------------------------------------------------------

template<class DT>
Heap<DT>::Heap(int maxNumber) : maxSize(maxNumber), size(0) {
	dataItems = new DT[maxSize];
}

template < class DT >
Heap<DT>::~Heap() {
	clear();
	delete[] dataItems;
}

//--------------------------------------------------------------------

template < class DT >
void Heap<DT>::insert(const DT& newElement) {
	if (isFull()) {
		cout << "Heap is full" << endl;
	}
	else {
		if (isEmpty()) {
			dataItems[size] = newElement;
		}
		else {
			DT tempItem;
			int child = size;
			int parent = (child - 1) / 2;

			dataItems[child] = newElement;

			while ((child > 0) && (dataItems[child].pty() > dataItems[parent].pty())) {
				tempItem = dataItems[parent];
				dataItems[parent] = dataItems[child];
				dataItems[child] = tempItem;

				child = (child - 1) / 2;
				parent = (child - 1) / 2;
			}
		}
		size++;
	}
}

template < class DT >
DT Heap<DT>::removeMax() {
	DT removeItem;

	if (isEmpty()) {
		cout << "Heap is Empty" << endl;
		removeItem.setPty(-1);
	}
	else {
		DT tempItem;
		int root = 0;
		int leftChild = 2 * root + 1;
		int rightChild = 2 * root + 2;

		removeItem = dataItems[0];
		dataItems[0] = dataItems[size - 1];
		size--;

		while (leftChild <= size - 1) {
			int biggerChild = (leftChild == size - 1) ? leftChild
				: (dataItems[leftChild].pty() <= dataItems[rightChild].pty()) ? rightChild
				: leftChild;

			if (dataItems[root].pty() < dataItems[biggerChild].pty()) {
				tempItem = dataItems[root];
				dataItems[root] = dataItems[biggerChild];
				dataItems[biggerChild] = tempItem;
			}
			root = 2 * root + 1;
			leftChild = 2 * root + 1;
			rightChild = 2 * root + 2;
		}
	}
	return removeItem;
}

template < class DT >
void Heap<DT>::clear() {
	size = 0;
}

//--------------------------------------------------------------------

template < class DT >
bool Heap<DT>::isEmpty() const {
	return (size == 0);
}

template < class DT >
bool Heap<DT>::isFull() const {
	return (size == maxSize);
}

//--------------------------------------------------------------------

template < class HD >
void Heap<HD>::showStructure() const {
	// Outputs the priorities of the data in a heap in both array
	// and tree form. If the heap is empty, outputs "Empty heap". This
	// operation is intended for testing/debugging purposes only.

	int j;   // Loop counter

	cout << endl;
	if (size == 0)
		cout << "Empty heap" << endl;
	else
	{
		cout << "size = " << size << endl;       // Output array form
		for (j = 0; j < maxSize; j++)
			cout << j << "\t";
		cout << endl;
		for (j = 0; j < size; j++)
			cout << dataItems[j].pty() << "\t";
		cout << endl << endl;
		showSubtree(0, 0);                        // Output tree form
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void Heap<DT>::showSubtree(int index, int level) const {
	// Recursive partner of the showStructure() function. Outputs the
	// subtree (subheap) whose root is stored in dataItems[index]. Argument
	// level is the level of this dataItems within the tree.

	int j;   // Loop counter

	if (index < size)
	{
		showSubtree(2 * index + 2, level + 1);        // Output right subtree
		for (j = 0; j < level; j++)        // Tab over to level
			cout << "\t";
		cout << " " << dataItems[index].pty();   // Output dataItems's pty
		if (2 * index + 2 < size)                // Output "connector"
			cout << "<";
		else if (2 * index + 1 < size)
			cout << "\\";
		cout << endl;
		showSubtree(2 * index + 1, level + 1);        // Output left subtree
	}
}