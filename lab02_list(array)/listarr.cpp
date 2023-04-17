// CSE2017-01 Data Structure
// Lab 02 - List(Array)
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 March 18
//
// listarr.cpp
// :Array implementation of the List ADT


#include <iomanip>
#include "listarr.h"

using namespace std;

//--------------------------------------------------------------------

List::List(int maxNumber) : maxSize(maxNumber), size(0), cursor(-1) {
	// Creates an empty list. Allocates enough memory for maxNumber
	// data items (defaults to defMaxListSize).

	// pre-lab
	dataItems = new DataType[maxNumber];
}

//--------------------------------------------------------------------

List:: ~List() {
	// Frees the memory used by a list.

	// pre-lab
	delete[] dataItems;
}

//--------------------------------------------------------------------

void List::insert(const DataType& newDataItem) throw (logic_error) {
	// Inserts newDataItem after the cursor. If the list is empty, then
	// newDataItem is inserted as the first (and only) data items in the
	// list. In either case, moves the cursor to newDataItem.

	//pre-lab
	if (isFull()) {
		cout << "List is Full!" << endl;
	}
	else {
		if (isEmpty()) cursor = -1;
		if (cursor != size - 1) { // for the case that cursor is in the middle of the array
			for (int i = size; i > cursor; i--) {
				dataItems[i] = dataItems[i - 1];
			}
		}
		cursor++;
		dataItems[cursor] = newDataItem;
		size++;
	}
}

//--------------------------------------------------------------------

void List::remove() throw (logic_error) {
	// Removes the data items  marked by the cursor from a list. Moves the
	// cursor to the next data item item in the list. Assumes that the
	// first list data items "follows" the last list data item.

	// pre-lab
	if (isEmpty()) {
		cout << "List is Empty!" << endl;
	}
	else {
		if (cursor == size - 1) { // for the case that cursor is at the end
			dataItems[cursor] = NULL;
			cursor = 0;
		}
		else {
			for (int i = cursor; i < size - 1; i++) {
				dataItems[i] = dataItems[i + 1];
				dataItems[i + 1] = NULL;
			}
		}
		size--;
	}
}

//--------------------------------------------------------------------

void List::replace(const DataType& newDataItem) throw (logic_error) {
	// Replaces the item marked by the cursor with newDataItem and
	// leaves the cursor at newDataItem.
	// Requires that the list is not empty

	// pre-lab
	if (isEmpty()) {
		cout << "List is Empty!" << endl;
	}
	else {
		dataItems[cursor] = newDataItem;
	}
}
//--------------------------------------------------------------------

void List::clear() {
	// Removes all the data items from a list.

	// pre-lab
	for (int i = 0; i < size; i++) {
		dataItems[i] = NULL;
	}
	size = 0;
	cursor = -1;
}

//--------------------------------------------------------------------

bool List::isEmpty() const {
	// Returns 1 if a list is empty. Otherwise, returns 0.

	// pre-lab
	return size == 0;
}

//--------------------------------------------------------------------

bool List::isFull() const {
	// Returns 1 if a list is full. Otherwise, returns 0.

	// pre-lab
	return size == maxSize;
}

//--------------------------------------------------------------------

bool List::gotoBeginning() throw (logic_error) {
	// Moves the cursor to the beginning of the list.

	// pre-lab
	bool result = 0;

	if (!isEmpty()) {
		cursor = 0;
		result = 1;
	}
	return result;
}

//--------------------------------------------------------------------

bool List::gotoEnd() throw (logic_error) {
	// Moves the cursor to the end of the list.

	// pre-lab
	bool result = 0;

	if (!isEmpty()) {
		cursor = size - 1;
		result = 1;
	}
	return result;
}

//--------------------------------------------------------------------

bool List::gotoNext() throw (logic_error) {
	// If the cursor is not at the end of a list, then moves the
	// cursor to the next item in the list and returns true. Otherwise,
	// returns false.

	// pre-lab
	bool result = 0;

	if (!isEmpty() && !(cursor == size - 1)) {
		cursor++;
		result = 1;
	}
	return result;
}

//--------------------------------------------------------------------

bool List::gotoPrior() throw (logic_error) {
	// If the cursor is not at the beginning of a list, then moves the
	// cursor to the preceeding item in the list and returns true.
	// Otherwise, returns false.

	// pre-lab
	bool result = 0;

	if (!isEmpty() && !(cursor == 0)) {
		cursor--;
		result = 1;
	}
	return result;
}

//--------------------------------------------------------------------

DataType List::getCursor() const throw (logic_error) {
	// Returns the item marked by the cursor.

	// pre-lab
	return dataItems[cursor];
}

//--------------------------------------------------------------------

void List::showStructure() const {
	// Outputs the data items in a list. If the list is empty, outputs
	// "Empty list". This operation is intended for testing/debugging
	// purposes only.

	// pre-lab
	cout << "size = " << size << "        cursor : " << cursor << endl;
	cout << "[ 0 ]   [ 1 ]   [ 2 ]   [ 3 ]   [ 4 ]   [ 5 ]   [ 6 ]   [ 7 ]" << endl;
	if (size == 0) cout << "Empty list";
	else {
		cout << "  ";
		for (int i = 0; i < size; i++) {
			cout << setw(8) << left << dataItems[i];
		}
	}
	cout << endl;
}

//--------------------------------------------------------------------

//in-lab
void List::moveToNth(int n) throw (logic_error) {
	// in-lab 2
	if (size < 2) {
		cout << "Require More Items!" << endl;
	}
	else {
		char *tempList = new char[size]; // temporary array

		for (int i = 0; i < size; i++) { // copying into tempList
			tempList[i] = dataItems[i];
			dataItems[i] = NULL;
		}

		dataItems[n] = tempList[cursor]; // moving item
		tempList[cursor] = NULL;

		for (int i = 0; i < size; i++) {
			if (!dataItems[i]) {
				for (int j = 0; j < size; j++) {
					if (tempList[j]) {
						dataItems[i] = tempList[j]; // reallocating
						tempList[j] = NULL;
						break;
					}
				}
			}
		}
		cursor = n;
		delete[] tempList;
	}
}

bool List::find(const DataType& searchDataItem) throw(logic_error) {
	// in-lab 3
	bool result = 0;

	if (isEmpty()) {
		cout << "List is Empty!" << endl;
	}
	else {
		for (int i = cursor; i < size; i++) {
			cursor = i;
			if (dataItems[i] == searchDataItem) {
				result = 1;
				break;
			}
		}
	}
	return result;
}