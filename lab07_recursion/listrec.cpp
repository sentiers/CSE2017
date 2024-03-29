// CSE2017-01 Data Structure
// Lab 07 - Recursion
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 April 28
//
// listrec.cpp
// :(Shell) Partial linked list implementation of the List ADT with additional recursive linked list functions


#include <iostream>
#include "listrec.h"

using namespace std;

//--------------------------------------------------------------------
//
// Insert your singly linked list implementations (from Laboratory 7)
// of the following functions:
//
//   - The ListNode class constructor
//
//   - The List class constructor, destructor, insert(), clear(), and
//     showstructure() functions. You may also need to add empty()
//     full(), and others.
//
//--------------------------------------------------------------------

template<class DT>
ListNode<DT>::ListNode(const DT& initData, ListNode* nextPtr) {
	dataItem = initData;
	next = nextPtr;
}

template<class DT>
List<DT>::List(int ignored) {
	head = NULL;
	cursor = head;
}

template<class DT>
List<DT>::~List() {
	clear();
	delete cursor;
	delete head;
}

template<class DT>
void List<DT>::insert(const DT& newData) {
	ListNode<DT>* newNode = new ListNode<DT>(newData, NULL);
	if (head == NULL) { // insert new data at the beginning
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

template<class DT>
void List<DT>::clear() {
	ListNode<DT>* tempNode;
	while (head == NULL) {
		tempNode = head;
		head = head->next;
		delete tempNode;
	}
	head = NULL;
	cursor = NULL;
}

template<class DT>
void List<DT>::showStructure() const {
	ListNode<DT>* tempNode = head;
	while (tempNode) {
		if (tempNode == cursor) {
			cout << "[" << tempNode->dataItem << "]";
		}
		else {
			cout << tempNode->dataItem;
		}
		tempNode = tempNode->next;
	}
	cout << endl;
	delete tempNode;
}

//--------------------------------------------------------------------
//
// Recursively implemented linked list functions used in the Prelab
// Exercise
//
//--------------------------------------------------------------------

template < class DT >
void List<DT>::write() const

// Outputs the data in a list from beginning to end. Assumes that
// objects of type DT can be output to the cout stream.

{
	cout << "List : ";
	writeSub(head);
	cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::writeSub(ListNode<DT>* p) const

// Recursive partner of the write() function. Processes the sublist
// that begins with the node pointed to by p.

{
	if (p != 0)
	{
		cout << p->dataItem;      // Output data
		writeSub(p->next);    // Continue with next node
	}
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>::insertEnd(const DT& newDataItem)

// Inserts newDataItem at the end of a list. Moves the cursor to
// newDataItem.

{
	insertEndSub(head, newDataItem);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::insertEndSub(ListNode<DT>*& p,
	const DT& newDataItem)

	// Recursive partner of the insertEnd() function. Processes the
	// sublist that begins with the node pointed to by p.

{
	if (p != 0)
		insertEndSub(p->next, newDataItem);    // Continue searching for
	else                                     // end of list
	{
		p = new ListNode<DT>(newDataItem, 0);  // Insert new node
		cursor = p;                           // Move cursor
	}
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>::writeMirror() const

// Outputs the data in a list from beginning to end and back
// again. Assumes that objects of type DT can be output to the cout
// stream.

{
	cout << "Mirror : ";
	writeMirrorSub(head);
	cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::writeMirrorSub(ListNode<DT>* p) const

// Recursive partner of the writeMirror() function. Processes the
// sublist that begins with the node pointed to by p.

{
	if (p != 0)
	{
		cout << p->dataItem;           // Output data (forward)
		writeMirrorSub(p->next);   // Continue with next node
		cout << p->dataItem;           // Output data (backward)
	}
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>::reverse()

// Reverses the order of the data items in a list.

{
	reverseSub(0, head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::reverseSub(ListNode<DT>* p, ListNode<DT>* nextP)

// Recursive partner of the reverse() function. Processes the sublist
// that begins with the node pointed to by nextP.

{
	if (nextP != 0)
	{
		reverseSub(nextP, nextP->next);   // Continue with next node
		nextP->next = p;                 // Reverse link
	}
	else
		head = p;                        // Move head to end of list
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>::deleteEnd()

// Deletes the data at the end of a list. Moves the cursor to the
// beginning of the list.

{
	deleteEndSub(head);
	cursor = head;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::deleteEndSub(ListNode<DT>*& p)

// Recursive partner of the deleteEnd() function. Processes the
// sublist that begins with the node pointed to by p.

{
	if (p->next != 0)
		deleteEndSub(p->next);   // Continue looking for the last node
	else
	{
		delete p;                // Delete node
		p = 0;                   // Set p (link or head) to null
	}
}

//--------------------------------------------------------------------

template < class DT >
int List<DT>::getLength() const

// Returns the number of data items in a list.

{
	return getLengthSub(head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
int List<DT>::getLengthSub(ListNode<DT>* p) const

// Recursive partner of the length() function. Processes the sublist
// that begins with the node pointed to by p.

{
	int result;   // Result returned

	if (p == 0)
		result = 0;                            // End of list reached
	else
		result = (getLengthSub(p->next) + 1);   // Number of nodes after
											   // this one + 1
	return result;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template < class DT >
void List<DT>::cRemove() {
	cRemoveSub(head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template < class DT >
void List<DT>::cRemoveSub(ListNode<DT>* p) {
	ListNode<DT>* tempNode = p;
	if (p->dataItem == 'c') {
		if (head == p) { // remove data at the beginning
			if (p->next) {
				p = p->next;
				head = p;
				cRemoveSub(p);
			}
			else { // when there is only one node
				p = NULL;
				head = NULL;
			}
		}
		else {
			ListNode<DT>* tempNode2 = head;
			while (tempNode2->next != p) {
				tempNode2 = tempNode2->next;
			}
			p = tempNode2; // p -> prior
			p->next = tempNode->next;

			if (p->next) { // remove data in the middle
				p = p->next;
				cRemoveSub(p);
			}
			else {// remove data at the end
				p = head;
				cursor = p; // move cursor
			}
		}
	}
	else if (p->next)
		cRemoveSub(p->next);
}