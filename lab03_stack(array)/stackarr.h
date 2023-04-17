// CSE2017-01 Data Structure
// Lab 03 - Stack(Array)
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 March 28
//
// stackarr.h
// :Class declaration for the array implementation of the Stack ADT


#include <iostream>

using namespace std;

const int defMaxStackSize = 10;   // Default maximum stack size

template < class DT >
class Stack
{
public:

	// Constructor
	Stack(int maxNumber = defMaxStackSize);

	// Destructor
	~Stack();

	// Stack manipulation operations
	void push(const DT& newElement);    // Push element
	DT pop();                             // Pop element
	void clear();                         // Clear stack

	// Stack status operations
	bool isEmpty() const;                    // Stack is empty
	bool isFull() const;                     // Stack is full

	// Output the stack structure -- used in testing/debugging
	void showStructure() const;

private:

	// Data members
	int maxSize,   // Maximum number of elements in the stack
		top;       // Index of the top element
	DT* element;   // Array containing the stack elements
};