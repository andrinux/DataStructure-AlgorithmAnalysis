/*
* You have two very large binary trees: T1, with millions of nodes, and T2, 
* with hundreds of nodes. Create an algorithm to decide if T2 is a subtree of T1
*/

#include <iostream>
#include "BinaryTree.h"
#include <stdlib.h>


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

//Inorder traversal.
bool isMatch(Node *p1, Node * p2){
	bool lMatch = false, rMatch = false;
	//root Node
    if(p1==NULL && p2==NULL)
        return true;
    //maybe only one is NULL
    if((p1 == NULL && p2 != NULL)||(p2 == NULL && p1!=NULL))
        return false;
    if(p1->data != p2->data)
        return false;
    
   lMatch = isMatch(p1->left, p2->left);
   rMatch = isMatch(p1->right, p2->right);
   
   return lMatch&&rMatch;

}

//check p2 is subtree of p1
bool isSubTree(Node *p1, Node * p2){
    if(p1 == NULL && p2 == NULL)
        return true;
    if(p1 != 0 && p2== NULL)
        return false;
    if(p1 == NULL && p2!=NULL)
        return false;
    //p1 p2 neither NULL
    if(p1->data != p2->data)
        return isSubTree(p1->left, p2)||isSubTree(p1->right, p2);
    else
        return isMatch(p1, p2);
}

int main()
{

	int D1[18] = {0, 4, 5, 7, 3, 1, 2, 14, 11, 10, 9, 8, 15, 6, 12, 13, 20, 17};
	BinaryTree T1;
	T1.root = ArrayToTree(D1, NULL, 0, 14);
	T1.print();

	int D2[7] = { 11, 10, 9, 8, 15, 6, 12 };
	BinaryTree T2;
	T2.root = ArrayToTree(D2, NULL, 0, 6);
	T2.print();

    int D3[18] = {0, 4, 5, 7, 3, 1, 2, 14, 11, 10, 9, 8, 15, 6, 12, 13, 20, 17};
	BinaryTree T3;
	T3.root = ArrayToTree(D3, NULL, 0, 14);
	T3.print();

	if(isSubTree(T1.root, T2.root))
        std::cout << "Yes, Matched." << std::endl;
    else
        std::cout << "No, DisMatched." << std::endl;

	return 0;
}
