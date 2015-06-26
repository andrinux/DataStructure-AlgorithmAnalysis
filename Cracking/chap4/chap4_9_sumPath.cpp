/*
* You are given a binary tree in which each node contains a value. Design an algorithm to print 
* all paths which sum up to that value. Note that it can be any path in the tree - it does not 
* have to start at the root.
*/

//path may be not unique, so try to find all of them.

#include <iostream>
#include "BinaryTree.h"

Node* ArrayToTree(int a[], Node * parent, int start, int end){
	//base case.
	if (start > end)
		return NULL;
	BinaryTree * BST = new BinaryTree();
	int mid = (start + end) / 2;
	//general case
	BST->root = new Node(a[mid]);
	BST->root->parent = parent;
	BST->root->left = ArrayToTree(a, BST->root, start, mid - 1);
	BST->root->right = ArrayToTree(a, BST->root, mid + 1, end);
	return BST->root;
}

//Find a path summing to a given value, with parent node
void PathFinder(int value, Node * root){

}

//Second Version without parent node in the 'Node'
void PathFinder_2(int value, Node *root){
}


int main()
{
    int D[22] = {0, 4, 5, 7, 3, 1, 2, 7, 9, 11, 5, 14, 11, 10, 9, 8, 15, 6, 12, 13, 20, 17};
	BinaryTree T;
	T.root = ArrayToTree(D, NULL, 0, 21);
	T.print();

    return 0;
}

