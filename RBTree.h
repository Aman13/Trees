//#ifndef RBTree_H
//#define RBTree_H

#include <iostream>
#include <string>
#include <stdexcept>

class RBTree	{

public:

	RBTree();

/*	RBTree(const RBTree & source);

	RBTree & operator= (const RBTree & source);

	~RBTree();
*/
	bool insert(int value);

	bool search(int value);

	bool remove(int value);

	//int dump(int n);

	int size()	const;

	void PrintInOrder();

class Node	{
public:
	int data;
	Node* left;
	Node* right;
	Node* parent;
	bool isBlack;

	Node(int value) : data(value), left(NULL), right(NULL), parent(NULL), isBlack(0)	{};
};

private:

	void fixTree(Node* value);

	void siblingFinder(Node* value);

	void grandpaFinder(Node* value);

	void uncleFinder(Node* value);

	void insertCase1(Node* value);

	void insertCase2(Node* value);

	void insertCase3(Node* value);

	void insertCase4(Node* value);

	void insertCase5(Node* value);

	void rightR(Node* value);

	void leftR(Node* value);

	void successor(Node* value);

	void deletion(Node* value, Node* child);

	void replaceNode(Node* value, Node* child);

	void deleteCase1(Node* value);

	void deleteCase2(Node* value);

	void deleteCase3(Node* value);

	void deleteCase4(Node* value);

	void deleteCase5(Node* value);

	void deleteCase6(Node* value);

	void quickprint(Node* value)	const;

	//int inorder(Node* value, int arr[], int n);

	Node* root;
	Node* grandpa;
	Node* uncle;
	Node* sibling;
	Node* locator;
	Node* child;

	int counter;

};

//#include "RBTree.cpp"
//#endif