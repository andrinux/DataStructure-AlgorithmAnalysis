#include <iostream>
#include "myList.h"
#include <vector>
#include <iomanip>

//Destructor
myList::~myList()
{
	//this->destroyList(head);
	this->destroyList_Iter(head);
}

//Copy constructor
//Still doesn't work
myList::myList(const myList& rgt){
	this->copyList(rgt);
}

void myList::copyList(const myList& rgt){
	this->head = NULL;
	Node* p = rgt.head;
	Node *tmp;
	while (p != NULL){
		Node *newNode = new Node(p->value);
		if (head == NULL){
			head = newNode;
			tmp = head;
		}
		else{
			tmp->next = newNode;
			tmp = newNode;
		}
		p = p->next;
	}
	tmp->next = NULL;
	
}


//Always has problem with Destroy List
//pay attention to it here.
//Two versions: Recursive and Iterative
void myList::destroyList(Node* head){
	if (head == NULL)
		return;
	destroyList(head->next);
	delete head;
	this->head = NULL; //Must "this" here?
}

void myList::destroyList_Iter(Node* head){
	if (head == NULL)
		return;
	Node *p;
	while (head != NULL){
		p = head->next;
		delete head;
		head = p;
	}
	head = NULL;
	this->head = NULL;
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
		std::cout <<std::setw(2)<< cur->value << "->";
		cur = cur->next;
	}
	std::cout << std::endl;
	return;
}

//Implementation of single list reverse has several different ways to do.
//Recursion method and Iterative method
//(1) Store in a stack/array and reset the values again. Easy but waste space.
void do_reverse_v1(Node * head){
	if (head == NULL || head->next == NULL)
		return;
	std::vector<int> data;
	Node *p=head;
	while(p != NULL){
		data.push_back(p->value);
		p = p->next;
	}
	p = head;
	for(int i=data.size()-1; i >= 0; i-- ){
		p->value =  data[i];
		p = p->next;
	}
	//head didn't change address
}

//Version-2
//Use three pointers, don't change value, 
//just change the direction of all connectors
//Note that the refrence symbol here cannot be omitted!
void do_reverse_v2(Node *& head){
	//std::cout << "Head is: " << head->value << std::endl;
	if(head==NULL || head->next==NULL) // 0 or 1 node
		return;
	Node *pre = NULL;
	Node *p = head;
	Node *next = head->next;
	while (p->next != NULL){
		//std::cout << "Change: p: " << p->value << std::endl;
		p->next = pre;
		pre = p; 
		p = next;
		next = p->next;
	}
	head = p;
	head->next = pre;
	//std::cout << "head is changed to: " << head->value << std::endl;
}

//Version-3
//Move each node to right after head, and finally change the head to tail
//Seems not so elegant, a bit too much 'if clause'
void do_reverse_v3(Node* & head){
	if (head == NULL || head->next == NULL)
		return;
	Node *p;
	Node *next;
	Node *tmp;
	if (head->next->next != NULL){//more than 2 nodes, seems ugly for so
		p = head->next->next;
		next = p->next;
		head->next->next = NULL;//Set 2 as end node
		while (p != NULL){
			tmp = head->next;
			//Move p to the loc after head
			head->next = p;
			p->next = tmp;
			//Move to the next one
			p = next;
			if (p != NULL)
				next = p->next;
		}
	}
	//Change the head
	p = head;
	head = head->next;
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = p;
	p->next = NULL;
}

// Rewrite Idea V-3: To be cleaner
// always keep |p-cur-next|
void do_reverse_v3R(Node* & head){
	//Only 0 or 1 node, just return
	if (head == NULL || head->next == NULL)
		return;
	//At least 2 node
	Node *p = head->next;
	Node * cur = p->next;
	Node *next;
	while (cur != NULL){
		next = cur->next;
		//Insert 'cur' after head
		cur->next = head->next;
		head->next = cur;
		//update cur
		cur = next;
	}
	//Become a circular list
	p->next = head;
	head = head->next;
	p->next->next = NULL;//Break the circle

}


//Version-4 
//Recursion Solution, seems good and smooth
void do_reverse_v4(Node* & head){
	if (head == NULL || head->next == NULL)
		return;
	Node *small = head->next;
	do_reverse_v4(small);
	Node *p = small;
	while (p->next != NULL)
		p = p->next;
	p->next = head;
	head->next = NULL;
	head = small;
}

void myList::reverse()
{
	do_reverse_v4(this->head);
}


















