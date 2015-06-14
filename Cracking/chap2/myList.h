#ifndef _MY_LIST_H_
#define _MY_LIST_H_

#include <iostream>

class Node{
public:
	Node* next;
	int value;
public:
	Node() { value = 0; next = NULL; }
	Node(int d) { value = d; next = NULL; }
};


class myList{
public:
	Node *head;
public:
	myList() { head  = NULL; }
	~myList();
	void destroyList();
	void push_back(int d);
	void printList();
	void rmDup();
	void rmDup_v1();
	Node*  rmNode(Node* cur);
};

#endif