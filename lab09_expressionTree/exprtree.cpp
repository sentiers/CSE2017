// CSE2017-01 Data Structure
// Lab 09 - Expression Tree
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 May 12
//
// exprtree.cpp
// :Linked implementation of the Expression Tree ADT


#include "exprtree.h"
#include <iostream>

using namespace std;

//--------------------------------------------------------------------

ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode* leftPtr, ExprTreeNode* rightPtr) {
	element = elem;
	left = leftPtr;
	right = rightPtr;
}

//--------------------------------------------------------------------

ExprTree::ExprTree() {
	root = 0;
}

ExprTree::~ExprTree() {
	clear();
}

//--------------------------------------------------------------------

void ExprTree::build() {
	buildSub(root);
}

void ExprTree::buildSub(ExprTreeNode*& p) {
	char e;
	cin >> e;

	p = new ExprTreeNode(e, 0, 0);

	if ((e == '+') || (e == '-') || (e == '*') || (e == '/')) {
		buildSub(p->left);
		buildSub(p->right);
	}
}

//--------------------------------------------------------------------

void ExprTree::expression() const {
	exprSub(root);
}

void ExprTree::exprSub(ExprTreeNode* p) const {
	char e = p->element;
	if ((e == '+') || (e == '-') || (e == '*') || (e == '/')) {
		cout << '(';
		exprSub(p->left);
		cout << e;
		exprSub(p->right);
		cout << ')';
	}
	else if ((e >= '0') && (e <= '9')) {
		cout << e;
	}
	else {
		cout << "ERROR -- There is an invalid input in arithmetic expression. Answer could be wrong." << endl;
		cout << e;
	}
}

//--------------------------------------------------------------------

float ExprTree::evaluate() const {
	if (root != 0)
		return evaluateSub(root);
}

float ExprTree::evaluateSub(ExprTreeNode* p) const {
	float result = 0;
	char e = p->element;

	if (e == '+') {
		result = evaluateSub(p->left) + evaluateSub(p->right);
	}
	else if (e == '-') {
		result = evaluateSub(p->left) - evaluateSub(p->right);
	}
	else if (e == '*') {
		result = evaluateSub(p->left) * evaluateSub(p->right);
	}
	else if (e == '/') {
		result = evaluateSub(p->left) / evaluateSub(p->right);
	}
	else if ((e >= '0') && (e <= '9')) {
		result = p->element - '0';
	}

	return result;
}

//--------------------------------------------------------------------

void ExprTree::clear() {
	clearSub(root);
	root = 0;
}

void ExprTree::clearSub(ExprTreeNode* p) {
	if (p != 0) {
		clearSub(p->left);
		clearSub(p->right);
		delete p;
	}
}

//--------------------------------------------------------------------

void ExprTree::showStructure() const {
	if (root == 0)
		cout << "Empty tree" << endl;
	else {
		cout << endl;
		showSub(root, 1);
		cout << endl;
	}
}

void ExprTree::showSub(ExprTreeNode* p, int level) const {
	int j;

	if (p != 0) {
		showSub(p->right, level + 1);
		for (j = 0; j < level; j++)
			cout << "\t";
		cout << " " << p->element;
		if ((p->left != 0) &&
			(p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";
		cout << endl;
		showSub(p->left, level + 1);
	}
}