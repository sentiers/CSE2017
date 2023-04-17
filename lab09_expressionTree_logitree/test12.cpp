// CSE2017-01 Data Structure
// Lab 09 - Expression Tree
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 May 12
//
// test12.cpp
// :Test program for the operations in the Expression Tree ADT


#include <iostream>
#include "logitree.h"    //in-lab

using namespace std;

void main()
{
	ExprTree testExpression;  // Test expression

	cout << endl << "Enter an expression in prefix form : ";

	testExpression.build();
	testExpression.showStructure();
	testExpression.expression();
	cout << " = " << testExpression.evaluate() << endl;

	cout << endl << "Clear the tree" << endl;
	testExpression.clear();
	testExpression.showStructure();

	system("pause");
}
