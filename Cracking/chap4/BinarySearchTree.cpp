/*
* Implementation of Binary Search Tree Structure.
*/

#include <iostream>
#include "BinarySearchTree.h"
#include <cmath>

static int M = 0;
BinarySearchTree::~BinarySearchTree(){
	this->destroy(this->root);
}

void BinarySearchTree::insert(const int &val){
	do_insert(val, root);
	size++;
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
//Recursion of destroy: Can be done iteratively as well, like print in level.
void BinarySearchTree::destroy(Node * root){
	if (root == NULL)
		return;
	destroy(root->left);
	destroy(root->right);
	delete root;
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
//Depth of leaf is zero. //Preferred Solution.Concise.
//Complexity: O(logN)
int BinarySearchTree::do_get_Depth(Node * p){
	if (p == NULL)
		return 0;
	int lDepth = do_get_Depth(p->left);
	int rDepth = do_get_Depth(p->right);
	int max = (lDepth > rDepth) ? lDepth : rDepth;
	return max +1;
}
//Iterative Version of Get Height, Similar to print in level.
int BinarySearchTree::do_get_Depth_I(Node *root){
	int depth = 0;
	std::queue<Node* > cur, next;
	cur.push(root);
	while (!cur.empty()){
		while (!cur.empty()){
			Node *p = cur.front();
			if (p->left !=NULL)
				next.push(p->left);
			if (p->right!=NULL)
				next.push(p->right);
			cur.pop();
		}
		//Need to clear next
		next.swap(cur);	
		depth++;
	}
	std::cout << "Depth by iterative is: " << depth << std::endl;
	return depth;
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
int BinarySearchTree::getHeight(Node * p){
	int maxDepth = 0;
	maxDepth = do_get_Depth(root);
	std::cout << "Max Depth is: " << maxDepth << std::endl;
	return maxDepth;
}


//For each node. check the height of left subtree and rightsubtree.
//A direct way is worst case O(N^2): skewed tree
bool BinarySearchTree::checkAVL(Node *p){
	//traversal
	bool res=false;
	if (p == NULL)
		return true;
	int lDepth = do_get_Depth(p->left);
	int rDepth = do_get_Depth(p->right);
	if (abs(lDepth - rDepth) >= 2)
		res = false;
	else
		res = checkAVL(p->left) && checkAVL(p->right);
	return res;
}

//Version 2 is to reduce the time complexity by calculating the height together
bool BinarySearchTree::checkAVL_2(Node *p){
	int height = 0;
	return do_checkAVL_2(p, height);
}

bool BinarySearchTree::do_checkAVL_2(Node *p, int &height){
	int LH = 0, RH = 0;//height of subtrees
	bool L_AVL = false, R_VAL = false;
	if (p == NULL){
		height = 0;
		return true;
	}
	L_AVL = do_checkAVL_2(p->left, LH);
	R_VAL = do_checkAVL_2(p->right, RH);
	height = (LH > RH ? LH : RH) + 1;
	if (abs(LH - RH) >= 2)
		return false;
	else
		return L_AVL && R_VAL;
}

bool BinarySearchTree::find(int val) const{
	Node *p = root;
	while (p != NULL){
		if (p->value == val)
			return true;
		else if (p->value < val)
			p = p->right;
		else
			p = p->left;
	}
		return false;
}

int BinarySearchTree::findMin(){
	Node *p = root;
	if (root == NULL){
		return -1;
	}
	while (p->left != NULL){
		p = p->left;
	}
	return p->value;
}

void BinarySearchTree::print_pre_order(Node * p){
	if (p == NULL)
		return;
	std::cout << p->value << "->";
	print_pre_order(p->left);
	print_pre_order(p->right);
}

void BinarySearchTree::print_in_order(Node * p){
	if (p == NULL)
		return;
	print_in_order(p->left);
	std::cout << p->value << "->";
	print_in_order(p->right);
}

void BinarySearchTree::print_post_order(Node * p){
	if (p == NULL)
		return;
	print_post_order(p->left);
	print_post_order(p->right);
	std::cout << p->value << "->";
}

//Iteratively
void BinarySearchTree::print_pre_order_I(Node * p){
	if(p == NULL)
		return;
	std::stack<Node*> toVisit;
	toVisit.push(p);
	while(!toVisit.empty()){
		p = toVisit.top();
		toVisit.pop();
		while(p != NULL){
			std::cout << p->value << "->";
			if(p->right != NULL)
				toVisit.push(p->right);
			p = p->left;
		}
	}
	std::cout <<"\n================="<< std::endl;
}

//A bit different from Pre order iteration
void BinarySearchTree::print_in_order_I(Node * p){
	if(p == NULL)
		return;
	std::stack<Node *> toVisit;
	while(p != NULL || !toVisit.empty()){
		if(p != NULL){
			if(p->right)
				toVisit.push(p->right);
			toVisit.push(p);
			p = p->left;
		}
		else{
			p = toVisit.top();
			std::cout<< p->value << "->";
			toVisit.pop();
			p = toVisit.top();
		}
	}

}

void BinarySearchTree::print_post_order_I(Node * p){
	if(p == NULL)
		return;
	//std::stack<Node *> toVisit;

}


//Iteratively Traversal
int BinarySearchTree::getSize(){
	do_getSize(root);
	return M;
}

//Why a static variable cannot get the size.
void BinarySearchTree::do_getSize(Node *p){
	if (p == NULL)
		return;
	print_in_order(p->left);
	M=M+1;
	print_in_order(p->right);
}

