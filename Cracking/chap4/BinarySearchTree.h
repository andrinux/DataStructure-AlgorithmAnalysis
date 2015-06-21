#ifndef _BinarySearchTree_H_
#define _BinarySearchTree_H_

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
private:
	Node * root;
public:
	//Constructor
	BinarySearchTree() : root(NULL) {}
	~BinarySearchTree();
	//Data
	void insert(int & val);
	//void erase(int & val);
	////Attributes
	//void getHeight();
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
	//void print_as_sideways_tree();
	////Search
	//void BFS();
	//void DFS();

};

#endif