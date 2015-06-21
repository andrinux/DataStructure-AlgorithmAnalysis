/*
* Implementation of Binary Search Tree Structure.
*/

#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree::~BinarySearchTree(){
	this->destroy(this->root);
}

void BinarySearchTree::insert(int & val){
	Node * newNode = new Node(val);
	Node * p = root;

}

void BinarySearchTree::destroy(Node * root){

}
