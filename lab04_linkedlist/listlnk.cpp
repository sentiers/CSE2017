// CSE2017-01 Data Structure
// Lab 04 - Linked List
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 April 2
//
// listlnk.cpp
// :List implementation of the List ADT


#include "listlnk.h"
#include <iostream>

using namespace std;

template<class DT>
ListNode<DT>::ListNode(const DT& nodeData, ListNode* nextPtr) {
	dataItem = nodeData;
	next = nextPtr;
}

template<class DT>
List<DT>::List(int ignored) {
	head = NULL;
	cursor = head;
}

//------------------------------------------------

template<class DT>
List<DT>::~List() {
	clear();
	delete cursor;
	delete head;
}

//------------------------------------------------

template<class DT>
void List<DT>::insert(const DT& newData) {
	if (isFull()) {
		cout << "List is Full" << endl;
	}
	else {
		ListNode<DT>* newNode = new ListNode<DT>(newData, NULL);
		if (isEmpty()) { // insert new data at the beginning
			head = newNode;
			cursor = head;
		}
		else if (cursor->next) { // insert new data in the middle
			newNode->next = cursor->next;
			cursor->next = newNode;
			cursor = newNode;
		}
		else { // insert new data at the end
			cursor->next = newNode;
			cursor = newNode;
		}
	}
}

//------------------------------------------------

template<class DT>
void List<DT>::remove() {
	if (isEmpty()) {
		cout << "List is Empty" << endl;
	}
	else {
		ListNode<DT>* tempNode = cursor;
		if (head == cursor) { // remove data at the beginning
			if (cursor->next) {
				gotoNext();
				head = cursor;
			}
			else { // when there is only one node
				cursor = NULL;
				head = NULL;
			}
		}
		else {
			gotoPrior();
			cursor->next = tempNode->next;
			if (cursor->next) // remove data in the middle
				gotoNext();
			else // remove data at the end
				gotoBeginning();
		}
		delete tempNode;
	}
}

//------------------------------------------------

template<class DT>
void List<DT>::replace(const DT& newData) {
	if (isEmpty())
		cout << "List is Empty" << endl;
	else
		cursor->dataItem = newData;
}

//------------------------------------------------

template<class DT>
void List<DT>::clear() {
	while (!isEmpty())
		remove();
}

//------------------------------------------------

template<class DT>
bool List<DT>::isEmpty() const {
	return (head == NULL);
}

//------------------------------------------------

template<class DT>
bool List<DT>::isFull() const {
	ListNode<DT>* tempNode = new ListNode<DT>(NULL, NULL);
	if (tempNode) {
		delete tempNode;
		return false;
	}
	else
		return true;
}

//------------------------------------------------

template<class DT>
void List<DT>::gotoBeginning() {
	if (isEmpty())
		cout << "List is Empty" << endl;
	else
		cursor = head;
}

//------------------------------------------------

template<class DT>
void List<DT>::gotoEnd() {
	if (isEmpty())
		cout << "List is Empty" << endl;
	else
		while (cursor->next)
			cursor = cursor->next;
}

//------------------------------------------------

template<class DT>
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

//------------------------------------------------

template<class DT>
bool List<DT>::gotoPrior() {
	bool result = false;
	if (isEmpty()) {
		cout << "List is Empty" << endl;
	}
	else if (cursor != head) {
		ListNode<DT>* tempNode = head;
		while (tempNode->next != cursor) {
			tempNode = tempNode->next;
		}
		cursor = tempNode;
		result = true;
	}
	return result;
}

//------------------------------------------------

template<class DT>
DT List<DT>::getCursor() const {
	if (isEmpty()) {
		cout << "List is Empty" << endl;
		return false;
	}
	else {
		return cursor->dataItem;
	}
}

template<class DT>	
void List<DT>::showStructure() const {
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
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

//------------------------------------------------

//in-lab
template<class DT>
void List<DT>::moveToBeginning() {
	if (isEmpty()) {
		cout << "List is Empty" << endl;
	}
	else {
		DT tempElement = getCursor();
		remove();
		ListNode<DT>* tempNode = new ListNode<DT>(tempElement, head);
		head = tempNode;
		cursor = head;
	}
}

template<class DT>
void List<DT>::insertBefore(const DT& newData) {
	if (isFull()) {
		cout << "List is Full" << endl;
	}
	else {
		if (cursor == head) { // insert new data at the beginning
			ListNode<DT>* newNode = new ListNode<DT>(newData, head);
			head = newNode;
			cursor = newNode;
		}
		else { // insert new data in the middle, and at the end
			gotoPrior();
			insert(newData);
		}
	}
}