// CSE2017-01 Data Structure
// Project3
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 June 7
//
// Tree.h
// :Class declarations for the linked implementation of the tree


#include <iostream>
#include <string>

using namespace std;

class Tree;

class TreeNode {
private:
	TreeNode(const string& elem, TreeNode* leftPtr, TreeNode* rightPtr);
	string element;
	TreeNode* left, * right;

	friend class Tree;
};

class Tree {
public:
	Tree();
	~Tree();

	void insert(const string& searchElement, const string& newElement);
	void remove(const string& deleteElement);
	bool retrieve(const string& searchElement, TreeNode*& treeNode) const;
	void clear();
	bool isEmpty() const;
	bool isFull() const;
	void showStructure() const;

private:
	void insertSub(TreeNode*& p, const string& newElement);
	void removeSub(TreeNode*& p, const string& deleteElement);
	void retrieveSub(TreeNode* p, const string& searchElement, TreeNode*& treeNode) const;
	void clearSub(TreeNode* p);
	void showSub(TreeNode* p, int level) const;

	TreeNode* root;
};