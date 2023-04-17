// CSE2017-01 Data Structure
// Lab 05 - queue
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 April 9
//
// queueLnk.cpp
// :Linked list implementation of the Queue ADT


#include "queueLnk.h"
#include <iostream>

using namespace std;

template<class DT>
QueueNode<DT>::QueueNode(const DT& nodeData, QueueNode* nextPtr) {
	dataItem = nodeData;
	next = nextPtr;
}

template <class DT>
Queue<DT>::Queue(int ignored) {
	front = NULL;
	rear = NULL;
}

template<class DT>
Queue<DT>::~Queue() {
	clear();
	delete front;
	delete rear;
}

template<class DT>
void Queue<DT>::enqueue(const DT& newData) {
	if (isFull())
		cout << "Queue is Full" << endl;
	else {
		QueueNode<DT>* newNode = new QueueNode<DT>(newData, NULL);
		if (isEmpty()) { // insert new data in the empty list
			front = newNode;
			rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
	}
}

template<class DT>
DT Queue<DT>::dequeue() {
	if (isEmpty())
		cout << "Queue is Empty" << endl;
	else {
		QueueNode<DT>* temp = front;
		DT tempData = temp->dataItem;
		if (front == rear) {
			front = NULL;
			rear = NULL;
		}
		else
			front = front->next;
		delete temp;
		return tempData;
	}
}

template <class DT>
void Queue<DT>::clear() {
	while (!isEmpty())
		dequeue();
}

template<class DT>
bool Queue<DT>::isEmpty() const {
	return (front == NULL);
}

template<class DT>
bool Queue<DT>::isFull() const {
	QueueNode<DT>* ptr = new QueueNode<DT>(NULL, NULL);
	if (ptr) {
		delete ptr;
		return false;
	}
	else
		return true;
}

template<class DT>
void Queue<DT>::showStructure() const {
	if (isEmpty())
		cout << "Empty Queue" << endl;
	else {
		for (auto i = front; i != NULL; i = i->next)
			cout << i->dataItem << "\t";
		cout << endl;
	}
}

template<class DT>
void Queue<DT>::putFront(const DT& newDataItem) {
	if (isFull())
		cout << "Queue is Full" << endl;
	else {
		QueueNode<DT>* newNode = new QueueNode<DT>(newDataItem, NULL);
		if (isEmpty()) { // insert new data in the empty list
			front = newNode;
			rear = newNode;
		}
		else {
			newNode->next = front;
			front = newNode;
		}
	}
}

template <class DT>
DT Queue<DT>::getRear() {
	if (isEmpty())
		cout << "Queue is Empty" << endl;
	else {
		DT tempData = rear->dataItem;
		if (front == rear)
			clear();
		else {
			QueueNode<DT>* temp = front;
			while (temp->next != rear)
				temp = temp->next;
			rear = temp;
			rear->next = NULL;
			temp = NULL;
		}
		return tempData;
	}
}

template<class DT>
int Queue<DT>::getLength() const {
	int length = 0;
	for (auto i = front; i != NULL; i = i->next)
		length++;
	return length;
}