/*
* Implementation of Binary Search Tree Structure.
*/

#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree::~BinarySearchTree(){
	this->destroy(this->root);
}

void BinarySearchTree::insert(const int &val){
	do_insert(val, root);
}

//Skip node if this value already exists
void BinarySearchTree::do_insert(const int & val, Node* & p){
	if (p == NULL){
		Node *newNode = new Node(val);
		p = newNode;
		return;
	}
	if (val < p->value)
		do_insert(val, p->left);
	else if (val > p->value)
		do_insert(val, p->right);
	else
		return;
}

void BinarySearchTree::destroy(Node * root){
	return;
}

//Print as a shape of Tree.
void BinarySearchTree::print_as_tree(){

}

//Print the tree in Horizontal Way
void BinarySearchTree::print_as_sideways_tree(){
	do_print_sideway(root, 0);
}

void BinarySearchTree::do_print_sideway(Node *p, int depth){
	if (p != NULL){
		do_print_sideway(p->right, depth + 1);
		for (int i = 0; i != depth; i++)
			std::cout << "   ";
		std::cout << p->value << std::endl;
		do_print_sideway(p->left, depth + 1);
	}
}
//Depth of leaf is zero.
int BinarySearchTree::do_get_Depth(Node * p, int depth){
	if (p == NULL)
		return 0;
	int lDepth = do_get_Depth(p->left, depth);
	int rDepth = do_get_Depth(p->right, depth);
	int max = (lDepth > rDepth) ? lDepth : rDepth;
	return max +1;
}

//Depth of root is zero. Traversal the whole tree, when met a leaf, store the depth.
//This would be very easy if 'parent' exists in Node.
void BinarySearchTree::getAllDepth(Node*root, int cur, std::vector<int>& depth){
	//preorder traversal
	Node* p = root;
	if (p == NULL)
		return;
	if (p->left == NULL && p->right == NULL){
		depth.push_back(cur);
		return;
	}
	getAllDepth(p->left, cur+1, depth);
	getAllDepth(p->right, cur+1, depth);
}

//get Height has two versions:
//(1) to get the max height, (2) get all the heights of leaf nodes 
void BinarySearchTree::getHeight(){
	Node * p = root;
	int maxDepth = 0;
	maxDepth = do_get_Depth(root, maxDepth);
	std::cout << "Max Depth is: " << maxDepth << std::endl;
	return;
}