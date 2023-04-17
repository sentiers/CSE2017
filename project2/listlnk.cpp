// CSE2017-01 Data Structure
// Project2
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 May 12
//
// listlnk.cpp
// :Linked list implementation of the micro-version of Facebook.


#include "listlnk.h"
#include <iostream>
#include <string>

using namespace std;

template<class DT>
Person<DT>::Person(const DT& nameData, Person* nextPtr) {
	name = nameData;
	next = nextPtr;
	friendList = new List<DT>();
}

template<class DT>
List<DT>::List(int ignored) {
	head = NULL;
	cursor = head;
}

template<class DT>
List<DT>::~List() {
	clear();
}

//------------------------------------------------

template<class DT>
void List<DT>::insert(const DT& newData) {
	if (isFull()) {
		cout << "List is Full" << endl;
	}
	else {
		Person<DT>* newNode = new Person<DT>(newData, NULL);
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

template<class DT>
void List<DT>::remove() {
	if (isEmpty()) {
		cout << "List is Empty" << endl;
	}
	else {
		Person<DT>* tempNode = cursor;
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

template<class DT>
bool List<DT>::isFull() const {
	Person<DT>* tempNode = new Person<DT>("", NULL);
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

template<class DT>
bool List<DT>::gotoPrior() {
	bool result = false;
	if (isEmpty()) {
		cout << "List is Empty" << endl;
	}
	else if (cursor != head) {
		Person<DT>* tempNode = head;
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
void List<DT>::showStructure() const {
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		Person<DT>* tempNode = head;
		while (tempNode) {
			cout << tempNode->name << " ";
			tempNode = tempNode->next;
		}
		cout << endl;
		delete tempNode;
	}
}

//------------------------------------------------

template < class DT >
void List<DT>::friends(const DT& p1, const DT& p2) {
	if (p1 == p2)
		cout << "ERROR - a person cannot friends himself" << endl;
	else if (!isExist_setCur(p1))
		cout << "ERROR - " << p1 << " is NOT exist on the list" << endl;
	else if (!isExist_setCur(p2))
		cout << "ERROR - " << p2 << " is NOT exist on the list" << endl;
	else if (cursor->friendList->isExist_setCur(p1))
		cout << "ERROR - they are friends already" << endl;
	else {
		isExist_setCur(p1);
		cursor->friendList->insert(p2);
		isExist_setCur(p2);
		cursor->friendList->insert(p1);

		cout << p1 << " and " << p2 << " are friends from now on" << endl;
	}
}

template < class DT >
void List<DT>::unfriends(const DT& p1, const DT& p2) {
	if (p1 == p2)
		cout << "ERROR - a person cannot unfriends himself" << endl;
	else if (!isExist_setCur(p1))
		cout << "ERROR - " << p1 << " is NOT exist on the list" << endl;
	else if (!isExist_setCur(p2))
		cout << "ERROR - " << p2 << " is NOT exist on the list" << endl;
	else if (!cursor->friendList->isExist_setCur(p1))
		cout << "ERROR - they are NOT friends already" << endl;
	else {
		isExist_setCur(p1);
		cursor->friendList->isExist_setCur(p2);
		cursor->friendList->remove();
		isExist_setCur(p2);
		cursor->friendList->isExist_setCur(p1);
		cursor->friendList->remove();

		cout << p1 << " and " << p2 << " are NOT friends anymore" << endl;
	}
}

template < class DT >
void List<DT>::printFriendList(const DT& p) {
	if (isExist_setCur(p))
		cursor->friendList->showStructure();
	else
		cout << "ERROR - " << p << " is NOT exist on the list" << endl;
}

template < class DT >
void List<DT>::isFriend(const DT& p1, const DT& p2) {
	if (p1 == p2)
		cout << "ERROR - a person cannot be friend of himself" << endl;
	else if (!isExist_setCur(p1))
		cout << "ERROR - " << p1 << " is NOT exist on the list" << endl;
	else if (!isExist_setCur(p2))
		cout << "ERROR - " << p2 << " is NOT exist on the list" << endl;
	else if (cursor->friendList->isExist_setCur(p1))
		cout << "Yes" << endl;
	else
		cout << "NO" << endl;
}

//------------------------------------------------

template < class DT >
bool List<DT>::isExist_setCur(const DT& person) {
	bool exist = false;
	Person<DT>* tempNode = head;
	while (tempNode) {
		if (tempNode->name == person) {
			cursor = tempNode; // set cursor if it is exist
			exist = true;
			break;
		}
		else tempNode = tempNode->next;
	}
	return exist;
}
