#ifndef _BinarySearchTree_H_
#define _BinarySearchTree_H_

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class Node{
public:
	int value;
	Node* left;
	Node* right;
public:
	Node() : value(0), left(NULL), right(NULL) {}
	Node(int val) : value(val), left(NULL), right(NULL) {}
};



class BinarySearchTree{
public:
	Node * root;
	int size;
public:
	//Constructor
	BinarySearchTree() : root(NULL), size(0) {}
	~BinarySearchTree();
	//Data
	void insert(const int & val);
	void do_insert(const int & val, Node* & p);
	bool erase(int  val);
	//bool erase(Node *p);
	////Attributes
	bool checkAVL(Node *p);
	bool checkAVL_2(Node *p);
	bool do_checkAVL_2(Node *p, int &height);
	int getHeight(Node *p);
	int do_get_Depth(Node * p);
	void getAllDepth(Node*p, int cur, std::vector<int> &depth);
	int do_get_Depth_I(Node *p);
	bool isEmpty() const { return this->root == NULL; }
	void destroy(Node * root);
	int getSize();
	void do_getSize(Node *p);
	//bool isEqual(BST& old);
	////Find
	bool find(int val) const;
	int findMin(Node *p);
	////Traversal
	void print_pre_order(Node * root);
	void print_in_order(Node * root);
	void print_post_order(Node * root);
	void print_pre_order_I(Node * root);
	void print_in_order_I(Node * root);
	void print_post_order_I(Node * root);
	//void print_level_orer();
	////Print
	void print_as_sideways_tree();
	void do_print_sideway(Node *p, int depth);
	void print_as_tree();
	////Search
	//void BFS();
	//void DFS();

};

#endif