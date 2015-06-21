#ifndef _BinarySearchTree_H_
#define _BinarySearchTree_H_

#include <iostream>
#include <vector>
#include <queue>

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
public:
	//Constructor
	BinarySearchTree() : root(NULL) {}
	~BinarySearchTree();
	//Data
	void insert(const int & val);
	void do_insert(const int & val, Node* & p);
	//bool erase(int & val);
	//bool erase(Node *p);
	////Attributes
	bool checkAVL(Node *p);
	int getHeight(Node *p);
	int do_get_Depth(Node * p);
	void getAllDepth(Node*p, int cur, std::vector<int> &depth);
	int do_get_Depth_I(Node *p);
	//void isEmpty();
	void destroy(Node * root);
	//int getSize();
	//bool isEqual(BST& old);
	////Find
	//bool find(int val);
	//int findMin();
	////Traversal
	//void print_pre_order();
	//void print_in_order();
	//void print_post_order();
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