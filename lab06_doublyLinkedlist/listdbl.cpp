// CSE2017-01 Data Structure
// Lab 06 - Doubly Linked List
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 April 15
//
// listdbl.cpp
// :Circular, doubly linked list implementation of the List ADT

#include <iostream>
#include "listdbl.h"

using namespace std;

template < class DT >
ListNode<DT>::ListNode(const DT& data, ListNode* priorPtr, ListNode* nextPtr)
	:dataItem(data), prior(priorPtr), next(nextPtr) {
}

// Constructor
template < class DT >
List<DT>::List(int ignored) {
	head = NULL;
	cursor = head;
}

// Destructor
template < class DT >
List<DT>::~List() {
	clear();
	delete cursor;
	delete head;
}

//------------ List manipulation operations ------------------

// Insert after cursor
template < class DT >
void List<DT>::insert(const DT& newDataItem) {
	if (isFull())
		cout << "List is Full" << endl;
	else {
		ListNode<DT>* newNode = new ListNode<DT>(newDataItem, NULL, NULL);

		if (isEmpty()) { // insert new data for the first time
			head = newNode;
			cursor = head;
		}
		else if (cursor->next) { // insert new data in the middle
			newNode->prior = cursor;
			newNode->next = cursor->next;
			cursor->next->prior = newNode;
			cursor->next = newNode;
			cursor = newNode;
		}
		else { // insert new data at the end
			newNode->prior = cursor;
			cursor->next = newNode;
			cursor = newNode;
		}
	}
}

// Remove data item
template < class DT >
void List<DT>::remove() {
	if (isEmpty()) {
		cout << "List is Empty" << endl;
	}
	else {
		ListNode<DT>* tempNode = cursor;
		if (head == cursor) { // remove data at the beginning
			if (cursor->next) {
				head = cursor->next;
				gotoBeginning();
				tempNode->next = NULL;
				cursor->prior = NULL;
			}
			else { // when there is only one node
				cursor = NULL;
				head = NULL;
			}
		}
		else if (cursor->next) {// remove data in the middle
			cursor->prior->next = cursor->next;
			cursor->next->prior = cursor->prior;
			gotoNext();
		}
		else {// remove data at the end
			cursor->prior->next = NULL;
			gotoBeginning();
		}
		delete tempNode;
	}
}

// Replace data item
template < class DT >
void List<DT>::replace(const DT& newElement) {
	if (isEmpty())
		cout << "List is Empty" << endl;
	else
		cursor->dataItem = newElement;
}

// Clear list
template < class DT >
void List<DT>::clear() {
	gotoBeginning();
	while (!isEmpty())
		remove();
}

//------------ List status operations ------------------

// List is empty
template < class DT >
bool List<DT>::isEmpty() const {
	return (head == NULL);
}

// List is full
template < class DT >
bool List<DT>::isFull() const {
	ListNode<DT>* tempNode = new ListNode<DT>();
	if (tempNode) {
		delete tempNode;
		return false;
	}
	else
		return true;
}

//------------ List manipulation operations ------------------

// Go to beginning
template < class DT >
void List<DT>::gotoBeginning() {
	if (isEmpty())
		cout << "List is Empty" << endl;
	else
		cursor = head;
}

// Go to end
template < class DT >
void List<DT>::gotoEnd() {
	if (isEmpty())
		cout << "List is Empty" << endl;
	else
		while (cursor->next)
			gotoNext();
}

// Go to next data item
template < class DT >
bool List<DT>::gotoNext() {
	bool result = false;
	if (isEmpty()) {
		cout << "List is Empty" << endl;
	}
	else if (cursor->next) {
		cursor = cursor->next;
		result = true;
	}
	return result;
}

// Go to prior data item
template < class DT >
bool List<DT>::gotoPrior() {
	bool result = false;
	if (isEmpty()) {
		cout << "List is Empty" << endl;
	}
	else if (cursor != head) {
		cursor = cursor->prior;
		result = true;
	}
	return result;
}

template < class DT >
DT List<DT>::getCursor() const {
	if (isEmpty()) {
		cout << "List is Empty" << endl;
	}
	else {
		return cursor->dataItem;
	}
}

//-----------------------------------------------------------

template < class DT >
void List<DT>::showStructure() const {
	if (isEmpty())
		cout << "Empty List" << endl;
	else {
		ListNode<DT>* tempNode = head;
		while (tempNode) {
			if (tempNode == cursor) {
				cout << "[" << tempNode->dataItem << "] ";
			}
			else {
				cout << tempNode->dataItem << " ";
			}
			tempNode = tempNode->next;
		}
		cout << endl;
		delete tempNode;
	}
}