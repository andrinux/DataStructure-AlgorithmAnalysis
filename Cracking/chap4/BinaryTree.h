#ifndef _Binary_Tree_H_
#define _Binary_Tree_H_

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node * parent;
public:
	Node() : data(0), left(NULL), right(NULL), parent(NULL) {}
	Node(int val) : data(val), left(NULL), right(NULL), parent(NULL) {}
};

class BinaryTree{
public:
	Node * root;
	
public:
	//Constructor
	BinaryTree() : root(NULL) {}
	BinaryTree(BinaryTree& old);
	~BinaryTree();
	//functions
	void print();
	
};

#endif