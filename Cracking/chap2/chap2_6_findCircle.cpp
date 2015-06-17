/*
* Given a circular linked list, implement an algorithm which returns node at the beginning 
* of the loop. DEFINITION Circular linked list: A (corrupt) linked list in which a node＊s 
* next pointer points to an earlier node, so as to make a loop in the linked list. 
* EXAMPLE input: A 每> B 每> C 每> D 每> E 每> C (the same C as earlier) output: C
*/

#include <iostream>
#include "myList.h"

//If contains circle, fast/slow will never be NULL but will be equal
//If no circle, fast/slow will goto NULL finally
bool checkCircle(Node * head){
	std::cout<<"CHECKING>>>"<<std::endl;
	if (head == NULL || head->next == NULL)
		return false;
	Node *fast = head;
	Node *slow = head;
	while (fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return true;
	}
	return false;
}

Node* findCircleStart(Node* head){
	//0 or 1 node inside, then no loops at all
	if(head == NULL || head->next == NULL)
		return NULL;
	Node * fast = head;
	Node * slow = head;
	while(fast!=NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow)
			break;
	}
	if(fast != slow){
		std::cout << "No circle in this list." << std::endl;
		 return NULL;
	}
	//To her indicate slow==fast
	fast = head;
	while(fast != slow){
		fast = fast->next;
		slow = slow->next;
	}
	
	return fast;

}

int  main()
{
	myList mylist;
	for (int i = 0; i != 15; i++)
		mylist.push_back(i);
	mylist.printList();
	Node *p = mylist.head;
	while (p->next != NULL)
		p = p->next;
	Node *m = mylist.head;
	for (int i = 0; i != 5; i++)
		m = m->next;
	std::cout<<"Value should be:" << m->value <<std::endl;
	p->next = m;

	bool circle = false;
	circle=checkCircle(mylist.head);
	if (circle==true)
		std::cout << "Have circle" << std::endl;
	else
		std::cout << "No circle" << std::endl;
	Node* res=NULL;
	res=findCircleStart(mylist.head);
	if(res!=NULL)
		std::cout<<"The starter value: " << res->value<<std::endl;
	/*
	* !!! Circular list will have problem in Desctructor
	*/
	std::cout << "This is Program End." << std::endl;
	return 1;
}