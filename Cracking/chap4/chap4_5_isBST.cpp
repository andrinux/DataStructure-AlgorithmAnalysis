/*
* Check if a Binary Tree is a BST or not.
*/

#include <iostream>
#include "BinarySearchTree.h"
#define INT_MIN -999999

//CHeck isBST
bool isBST(Node *p){
	bool lTree, rTree;
	if (p->left != NULL)
		lTree = (p->value > p->left->value) && isBST(p->left);
	else
		lTree=true;
	if (p->right != NULL)
		rTree = (p->value < p->right->value) && isBST(p->right);
	else
		rTree = true;
	return lTree&&rTree;

}

//Solution2 from CC BOOK, very clean.(not easy to think...)
//Like In order traversal
//I feel not that good to understand.
static int last = INT_MIN;
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
	std::cout << isBST(nBST.root)<<std::endl;
	nBST.root->left->left->left->left->value = 0;
	std::cout << isBST(nBST.root) << std::endl;
	nBST.root->right->left->value = 15;
	std::cout << isBST(nBST.root) << std::endl;
	return EXIT_SUCCESS;
}
