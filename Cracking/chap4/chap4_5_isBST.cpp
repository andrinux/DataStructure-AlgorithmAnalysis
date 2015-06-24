/*
* Check if a Binary Tree is a BST or not.
*/
//g++ -Wall chap4_5_isBST.cpp BinarySearchTree.cpp -std=c++0x -o test

#include <iostream>
#include "BinarySearchTree.h"
#define MIN -999999

//CHeck isBST
/****************************************************************
* This is WRONG CODE. Only check left<cur<right is not enough.
*****************************************************************/
bool isBST(Node *p){
	return true;
}

//Solution2 from CC BOOK, very clean.(not easy to think...)
//Like In order traversal
//I feel not that good to understand.
static int last = MIN;
bool isBST_v2(Node *p){
	if (p == NULL)
		return true;
	if (!isBST_v2(p->left)) return false;
	if (p->value < last) return false;
	last = p->value;
	if (!isBST_v2(p->right)) return false;
	return true;
	
}

//Iterative Version: like BFS.
bool isBST_I(Node *p){
	return true;
}



int main()
{
	BinarySearchTree nBST;
	nBST.insert(10); nBST.insert(5); nBST.insert(12); nBST.insert(3);
	nBST.insert(6); nBST.insert(11); nBST.insert(13); nBST.insert(2);
	nBST.insert(4); nBST.insert(7); nBST.insert(14); nBST.insert(1);
	nBST.print_as_sideways_tree();
	nBST.print_pre_order(nBST.root); std::cout << std::endl;
	nBST.print_pre_order_I(nBST.root);
	nBST.print_in_order(nBST.root);
	std::cout << "\n=================" << std::endl;
	nBST.print_post_order(nBST.root);
	std::cout << "\n=================" << std::endl;



	std::cout << "Size is " << nBST.getSize() << std::endl;

	std::cout << isBST(nBST.root) << "-" << isBST_v2(nBST.root) << std::endl;
	nBST.root->left->left->left->left->value = 0;
	std::cout << isBST(nBST.root) << "-" << isBST_v2(nBST.root) << std::endl;
	nBST.root->right->left->value = 15;
	std::cout << isBST(nBST.root) << "-" << isBST_v2(nBST.root) << std::endl;
	

	BinarySearchTree BST;
	BST.root = new Node(20);
	BST.root->left = new Node(10);
	BST.root->right = new Node(30);
	BST.root->left->right = new Node(25);
	std::cout << isBST(BST.root) <<"-"<<isBST_v2(BST.root)<< std::endl;

	std::cout << "Some finding tests:" << std::endl;
	std::cout << BST.find(10) << "-" << BST.find(31) << std::endl;
	return EXIT_SUCCESS;
}
