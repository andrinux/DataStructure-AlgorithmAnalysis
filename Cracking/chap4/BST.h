#ifndef _BST_H_
#define _BST_H_

class Node{
private:
	int data;
	Node* left;
	Node* right;
public:
	Node() : data(0), left(NULL), right(NULL) {}
	Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BST{
private:
	Node * root;
public:
	BST() : root(NULL) {}
	~BST();

};

#endif