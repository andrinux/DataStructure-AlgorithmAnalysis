#ifndef _Binary_Tree_H_
#define _Binary_Tree_H_

class Node{
private:
	int data;
	Node* left;
	Node* right;
public:
	Node() : data(0), left(NULL), right(NULL) {}
	Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BinaryTree{
private:
	Node * root;
	
public:
	//Constructor
	BinaryTree() : root(NULL) {}
	BinaryTree(BinaryTree& old);
	~BinaryTree();
	//functions
	void clear();
	void print();
	
};

#endif