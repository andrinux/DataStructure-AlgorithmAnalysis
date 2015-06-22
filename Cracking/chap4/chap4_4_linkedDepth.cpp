/*
* Given a binary search tree, design an algorithm which creates a linked list of all 
* the nodes at each depth (i.e., if you have a tree with depth D, you¡¯ll have D linked lists).
*/

#include <iostream>
#include "BinarySearchTree.h"
#include <list>

using namespace std;

void getLevel(BinarySearchTree &BST){
	vector<list<Node *> > lists;
	list<Node *> cur, next;
	Node *p = BST.root;
	cur.push_back(p); lists.push_back(cur);
	while (!cur.empty()){
		while (!cur.empty()){
			Node *p = cur.front();
			if (p->left) next.push_back(p->left);
			if (p->right) next.push_back(p->right);
			cur.pop_front();
		}
		//Now, cur is empty and next is full of next level nodes
		cur = next;
		lists.push_back(cur);
		next.clear();
	}
	lists.pop_back();
	//Print Lists
	list<Node*>::const_iterator itr;
	for (int i = 0; i != lists.size(); i++){
		itr = lists[i].begin();
		for (; itr != lists[i].end(); itr++){
			std::cout << (*itr)->value << "->";
		}
		std::cout << std::endl;
	}
}

int main()
{
	BinarySearchTree nBST;
	nBST.insert(10); nBST.insert(5); nBST.insert(12); nBST.insert(3);
	nBST.insert(6); nBST.insert(11); nBST.insert(13); nBST.insert(2);
	nBST.insert(4); nBST.insert(7); nBST.insert(14); nBST.insert(1);
	nBST.print_as_sideways_tree();
	getLevel(nBST);
	return EXIT_SUCCESS;
}