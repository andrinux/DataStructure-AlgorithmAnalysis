#include <iostream>
#include "myList.h"


//Destructor
myList::~myList()
{
	this->destroyList(head);
}

//Always has problem with Destroy List
//pay attention to it here.
//Two versions: Recursive and Iterative

void myList::destroyList(Node* head){
	if (head == NULL)
		return;
	Node* tmp = head->next;
	if (head != NULL){
		delete head;
		head = NULL;
	}
	
	head = tmp;
	destroyList(head);
}

void myList::push_back(int d){
	Node* newNode = new Node(d);
	if (head == NULL){
		head = newNode;
		return;
	}
	Node *cur = head;
	while (cur->next != NULL){
		cur = cur->next;
	}
	cur->next = newNode;
	return;
}

Node* myList::rmNode(Node* cur)
{
	//If head
	Node* tmp = head;
	Node* last = NULL;
	if (cur == head){
		head = head->next;
		if (tmp != NULL){
			delete tmp;
			tmp = NULL;
		}
		tmp = NULL;
		return head;
	}
	//Need to find the last node
	while (tmp != cur){
		last = tmp;
		tmp = tmp->next;
	}
	//Reconnect and clear up
	last->next = cur->next;
	if (cur != NULL){
		delete cur;
		cur = NULL;
	}
	cur = NULL;
	return last->next;
}

void myList::printList()
{
	Node* cur = head;
	if (head == NULL)
		return;
	while (cur != NULL){
		std::cout << cur->value << "->";
		cur = cur->next;
	}
	std::cout << std::endl;
	return;
}
