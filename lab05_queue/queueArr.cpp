// CSE2017-01 Data Structure
// Lab 05 - queue
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 April 9
//
// queueArr.cpp
// :Array implementation of the Queue ADT


#include "queueArr.h"
#include <iostream>

using namespace std;

template<class DT>
Queue<DT>::Queue(int maxNumber) : maxSize(maxNumber), front(-1), rear(-1) {
	element = new DT[maxSize];
}

template<class DT>
Queue<DT>::~Queue() {
	delete[] element;
}

template<class DT>
void Queue<DT>::enqueue(const DT& newData) {
	if (isFull())
		cout << "Queue is Full" << endl;
	else {
		if (isEmpty()) { // when newData is first data
			front = 0;
			rear = 0;
		}
		else
			rear = (rear + 1) % maxSize;
		element[rear] = newData;
	}
}

template<class DT>
DT Queue<DT>::dequeue() {
	if (isEmpty())
		cout << "Queue is Empty" << endl;
	else {
		DT temp = element[front];
		element[front] = NULL;
		if (front == rear) // when front and rear is the same
			clear();
		else {
			front = (front + 1) % maxSize;
		}
		return temp;
	}
}

template<class DT>
void Queue<DT>::clear() {
	for (int i = 0; i < maxSize; i++) {
		element[i] = NULL;
	}
	front = -1;
	rear = -1;
}

template<class DT>
bool Queue<DT>::isFull() const {
	return ((rear + 1) % maxSize == front);
}

template<class DT>
bool Queue<DT>::isEmpty() const {
	return (front == -1);
}

template<class DT>
void Queue<DT>::showStructure() const {
	if (isEmpty())
		cout << "Empty Queue" << endl;
	else {
		cout << "Front = " << front << " Rear = " << rear << endl;
		for (int i = 0; i < maxSize; i++)
			cout << i << "\t";
		cout << endl;

		for (int i = 0; i < maxSize; i++)
			cout << element[i] << "\t";
		cout << endl;
	}
}

template<class DT>
void Queue<DT>::putFront(const DT& newDataItem) {
	if (isFull())
		cout << "Queue is Full" << endl;
	else {
		if (isEmpty())
			enqueue(newDataItem);
		else
			front = (front - 1 + maxSize) % maxSize;
		element[front] = newDataItem;
	}
}

template<class DT>
DT Queue<DT>::getRear() {
	if (isEmpty())
		cout << "Queue is Empty" << endl;
	else {
		DT temp = element[rear];
		element[rear] = NULL;
		if (front == rear)
			clear();
		else
			rear = (rear - 1 + maxSize) % maxSize;
		return temp;
	}
}

template < class DT >
int Queue<DT>::getLength() const {
	int length = 0;
	if (!isEmpty())
		length = (front <= rear) ? rear - front + 1 : maxSize - (front - rear) + 1;
	return length;
}