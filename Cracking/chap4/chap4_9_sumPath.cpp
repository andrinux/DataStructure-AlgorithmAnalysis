/*
* You are given a binary tree in which each node contains a value. Design an algorithm to print 
* all paths which sum up to that value. Note that it can be any path in the tree - it does not 
* have to start at the root.
*/  

//path may be not unique, so try to find all of them.
//method 2 is not finished yet.

#include <iostream>
#include "BinaryTree.h"
#include <vector>

Node * ArrayToTree(int a[], Node * parent, int start, int end)
{

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


void printPath(Node * s, Node * e)
{
	while (s != NULL) {
		if (s->parent != NULL)
			std::cout << s->data << "[" << s->parent->data << "]->";
		else
			std::cout << s->data << "[X]->";
		if (s == e)
			break;
		else
			s = s->parent;
	}
	std::cout << std::endl;
	return;
}


//Search from p to root
void SearchUp(int value, Node * p)
{

	int sum = 0;
	Node * start = p;
	while (p != NULL) {
		sum += p->data;
		if (sum == value)
			printPath(start, p);
	p = p->parent;
	}
}


//Find a path summing to a given value, with parent node
//In order traversal. for each node, do a reverse tracing back to root. 
//For each back tracing, the start point is fixed.
void PathFinder(int value, Node * p)
{
	if (p == NULL)
		return;
	PathFinder(value, p->left);
	SearchUp(value, p);
	PathFinder(value, p->right);
}

void PrintPathVec(std::vector<Node*> path, int s, int e){
    for(int i = e; i >= s ; i--)
        std::cout << path[i]->data << "->";
    std::cout << std::endl;
}

//Search vector from begin to end
void SearchDown(int value, Node* p, std::vector<Node*> path){
    int sum = 0;
    for (unsigned int s = 0; s != path.size(); s++){
        sum = 0;
        for(unsigned int i = s; i!= path.size(); i++){
            sum += (path[i]->data);
            if(sum == value)
                PrintPathVec(path, s, i);
        }
    }
}

//Second Version without parent node in the 'Node'
//Then we have to search from root.
void PathFinder_2(int value, Node * p, std::vector<Node*> path)
{
    if(p == NULL)
        return;
    path.push_back(p);
    PathFinder_2(value, p->left, path);
    SearchDown(value, p, path);
    PathFinder_2(value, p->right, path);
} 


int main() 
{
	int D[22] = { 0, 4, 5, 7, 3, 1, 2, 7, 9, 11, 5, 14, 11, 10, 9, 8, 15, 6, 12, 13, 20, 17 };
	BinaryTree T;
	T.root = ArrayToTree(D, NULL, 0, 21);
	T.print();
    std::vector<Node *> path;
	//PathFinder(15, T.root, path);
    std::cout <<"-------------------\n";
	PathFinder_2(15, T.root, path);
	return 0;
}


