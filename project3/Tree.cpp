// CSE2017-01 Data Structure
// Project3
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 June 7
//
// Tree.cpp
// :Implementation of the Tree


#include "Tree.h"
#pragma once

using namespace std;

TreeNode::TreeNode(const string& elem, TreeNode* leftPtr, TreeNode* rightPtr)
	: element(elem), left(leftPtr), right(rightPtr) {
}

Tree::Tree() : root(NULL) {
}

Tree::~Tree() {
	clear();
}

//--------------------------------------------------------------------
// Insert
void Tree::insert(const string& searchElement, const string& newElement) {
	TreeNode* tempNode = new TreeNode("", NULL, NULL);
	if (isFull()) {
		cout << "Tree is Full" << endl;
	}
	if (isEmpty()) { // CEO
		insertSub(root, newElement);
	}
	else if (retrieve(searchElement, tempNode)) {
		insertSub(tempNode->left, newElement);
	}
	else {
		delete tempNode;
		cout << "ERROR - Cannot Find " << searchElement << endl;
	}
}

void Tree::insertSub(TreeNode*& p, const string& newElement) {
	if (p == NULL) {
		p = new TreeNode(newElement, NULL, NULL);
	}
	else {
		insertSub(p->right, newElement);
	}
}

//--------------------------------------------------------------------
// Remove
void Tree::remove(const string& deleteElement) {
	TreeNode* tempNode = new TreeNode("", NULL, NULL);
	if (retrieve(deleteElement, tempNode)) {
		removeSub(root, deleteElement);
	}
	else {
		delete tempNode;
		cout << "ERROR - Cannot Find " << deleteElement << endl;
	}
}

void Tree::removeSub(TreeNode*& p, const string& deleteElement) {
	if (p != NULL) {
		if (p->element == deleteElement) {
			TreeNode* tempNode = p;
			if (p->left == NULL) {
				p = p->right;
				delete tempNode;
			}
			else {
				p->element = p->left->element;
				removeSub(p->left, p->left->element);
			}
		}
		else {
			removeSub(p->left, deleteElement);
			removeSub(p->right, deleteElement);
		}
	}
}

//--------------------------------------------------------------------
// Retrieve 
bool Tree::retrieve(const string& searchElement, TreeNode*& treeNode) const {
	retrieveSub(root, searchElement, treeNode);
	return (treeNode->element == searchElement);
}

void Tree::retrieveSub(TreeNode* p, const string& searchElement, TreeNode*& treeNode) const {
	if (p != NULL) {
		if (p->element == searchElement) {
			treeNode = p;
		}
		retrieveSub(p->left, searchElement, treeNode);
		retrieveSub(p->right, searchElement, treeNode);
	}
}

//--------------------------------------------------------------------
// Clear
void Tree::clear() {
	clearSub(root);
	root = NULL;
}

void Tree::clearSub(TreeNode* p) {
	if (p->left)
		clearSub(p->left);
	if (p->right)
		clearSub(p->right);
	delete p;
}

//--------------------------------------------------------------------
// Empty / Full
bool Tree::isEmpty() const {
	return root == NULL;
}

bool Tree::isFull() const {
	TreeNode* tempNode = new TreeNode("", NULL, NULL);
	if (tempNode != NULL) {
		delete tempNode;
		return false;
	}
	return true;
}

//--------------------------------------------------------------------
// Show Structure
void Tree::showStructure() const {
	if (isEmpty()) {
		cout << "Empty tree" << endl;
	}
	else {
		cout << endl;
		showSub(root, 0);
		cout << "------------------------------------------------------------" << endl;
	}
}

void Tree::showSub(TreeNode* p, int level) const{
	if (p != NULL){
		for (int i = 0; i < level; i++)
			cout << '+';
		cout << p->element << endl;
		showSub(p->left, level + 1);
		showSub(p->right, level);
	}
}

//--------------------------------------------------------------------
// Main Program
void main() {
	cout << "===============================================================" << endl;
	cout << "===============================================================" << endl;
	cout << "================= Organization Tree Program ===================" << endl;
	cout << "===============================================================" << endl;
	cout << "===============================================================" << endl;

	Tree testTree;
	int cursor1, cursor2;
	string str, one, two, three;

	while (true) {
		getline(cin, str, '\n');
		cursor1 = str.find_first_of(" ");
		one = str.substr(0, cursor1);

		if (one == "print") {
			testTree.showStructure();
		}
		else if (one == "fire") {
			cursor2 = str.find_last_of(" ");
			two = str.substr(cursor1 + 1, cursor2 - cursor1 - 1);
			testTree.remove(two);
		}
		else {
			cursor2 = str.find_last_of(" ");
			two = str.substr(cursor1 + 1, cursor2 - cursor1 - 1);
			three = str.substr(cursor2 + 1, str.length() - cursor2);

			if (two == "hires") {
				testTree.insert(one, three);
			}
			else if (testTree.isEmpty()) { //CEO
				testTree.insert("", one);
			}
			else {
				cout << "ERROR - Unknown Command" << endl;
			}
		}
	}
}

