// CSE2017-01 Data Structure
// Lab 03 - Stack(Array)
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 March 28
//
// stackdwn.cpp
// :Array implementation of the Stack ADT downward


#include "stackarr.h"

//--------------------------------------------------------------------

template <class DT>
Stack<DT>::Stack(int maxNumber) :maxSize(maxNumber), top(maxNumber) {
	element = new DT[maxSize];
	for (int i = 0; i < maxSize; i++) {
		element[i] = NULL;
	}
}

//--------------------------------------------------------------------

template <class DT>
Stack<DT>:: ~Stack() {
	delete[] element;
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::push(const DT& newElement) {
	if (isFull()) {
		cout << "Stack is Full" << endl;
	}
	else {
		top--;
		element[top] = newElement;
	}
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop() {
	if (isEmpty()) {
		cout << "Stack is Empty" << endl;
		return NULL;
	}
	else {
		DT temp = element[top];
		element[top] = NULL;
		top++;
		return temp;
	}
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear() {
	for (int i = maxSize - 1; i > -1; i--) {
		element[i] = NULL;
	}
	top = maxSize;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const {
	return top == maxSize;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const {
	return top == 0;
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::showStructure() const {
	if (isEmpty())
		cout << "Empty Stack" << endl;
	else {
		for (int i = 0; i < maxSize; i++) {
			if (element[i])
				cout << "| " << element[i] << " |";
			else
				cout << "| " << "Empty" << " |";
		}
		cout << endl;
	}
}