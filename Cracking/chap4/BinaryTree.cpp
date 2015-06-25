#include <iostream>
#include "BinaryTree.h"

//Implementations of functions in BinaryTree(not BST)
BinaryTree::BinaryTree(BinaryTree& old){

}

BinaryTree::~BinaryTree()
{

}

void do_print(Node * p, int depth){
	if (p == NULL)
		return;
	if (p->right)
		do_print(p->right, depth + 1);
	for (int i = 0; i != depth; i++)
		std::cout << "     ";
	//if (p->parent)
	//	std::cout << p->data << "[" << p->parent->data << "]" << std::endl;
	//else
	//	std::cout << p->data << "[X]" << std::endl;
	std::cout << p->data << std::endl;
	if (p->left)
		do_print(p->left, depth + 1);
	return;
}

void BinaryTree::print(){
	int depth = 0;
	do_print(root, depth);
	std::cout << "-----------------------" << std::endl;
	return;
}
