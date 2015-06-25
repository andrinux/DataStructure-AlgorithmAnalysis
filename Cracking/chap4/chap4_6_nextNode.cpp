/*
* Write an algorithm to find the ¡®next¡¯ node (i.e., in-order successor) of a given node 
* in a binary search tree where each node has a link to its parent.
*/

#include <iostream>

class Node{
public:
	Node * left;
	Node * right;
	Node * parent;
	int value;
public:
	Node(int val) : left(NULL), right(NULL), parent(NULL), value(val) {}
};

class BSTree{
public:
	Node * root;
public:
	BSTree() : root(NULL) {}
	//void print();
	//void do_print(Node *p, int depth);
	//void insert(const int &val);
	//void do_insert(const int & val, Node* & p, Node * &parent);
};



Node * findNext(Node * p,  int val){
	if (p == NULL)
		return NULL;
	Node *next = NULL;
	Node * par = NULL;
	if (p->right != NULL){
		next = p->right;
		while (next->left)
			next = next->left;
	}
	else{
		//until find a larger one
		while (p && p->parent->right == p){
			p = p->parent;
		}
		next = p->parent;
	}
	return next;
}



int main()
{
	BSTree my;
	//my.insert(10); my.insert(9); my.insert(12);
	//findNext(my.root, 11);
	//my.print();
	return 1;
}
