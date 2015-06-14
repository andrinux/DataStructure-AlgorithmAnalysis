#include <iostream>
#include "myList.h"


//Destructor
myList::~myList()
{
	this->destroyList();
}
//Always has problem with Destroy List

void myList::destroyList(){
	if (head == NULL)
		return;
	Node* newHead;
	while (head != NULL){
		newHead = head->next;
		delete head;
		head = newHead;
	}
	head = NULL;

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
		delete tmp;
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
	delete cur;
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
