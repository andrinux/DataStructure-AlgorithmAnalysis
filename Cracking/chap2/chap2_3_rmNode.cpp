/*
* 2.3: Implement an algorithm to delete a node in the middle of a single linked list, 
* given only access to that node.
* Note: no head pointer
*/


#include <iostream>
#include "myList.h"

//Copy Node according to the pointer(address)
void copyNodeData(Node* dst, Node* src){
	if (src == NULL){
		dst = NULL;
		return;
	}
	dst->value = src->value;
	//dst->next = src->next;
}

//No head pointer to remove Node
//Version-1: ugly code
void removeNode_v1(myList & my, Node* cur){
	if(cur == NULL)
		return;
	//cur is the tail node
	if(cur->next == NULL){
		cur->value='\0';
		delete cur;
		cur = NULL;
		return;
	}
	while(cur->next != NULL){
		copyNodeData(cur, cur->next);
		//To be the end of list
		if(cur->next->next == NULL){
			delete cur->next;
			cur->next = NULL;
			return;
		}
		cur=cur->next;
	}
}

//A clearner version
void removeNode(myList &my, Node* cur){
	if(cur==NULL)
		return;
	if(cur->next == NULL){
		cur->value=NULL;
		delete cur;
		cur=NULL;
		return;
	}
	//cur is head or middle Nodes
	while(cur->next->next != NULL){
		cur->value = cur->next->value;
		cur=cur->next;
	}
	// 2nd to last node
	cur->value=cur->next->value;
	delete cur->next;
	cur->next=NULL;
	return;
}


int  main()
{
	myList mylist;
	mylist.push_back(0); mylist.push_back(1); mylist.push_back(2);
	mylist.push_back(3); mylist.push_back(1); mylist.push_back(4);
	mylist.push_back(5); mylist.push_back(2); mylist.push_back(7);
	mylist.push_back(8); mylist.push_back(2); mylist.push_back(9);
	mylist.printList();
	Node* head = mylist.head;
	Node* ptr = head->next; ptr = ptr->next; ptr = ptr->next; ptr = ptr->next;ptr = ptr->next;
	std::cout<<ptr->value<<std::endl;
	removeNode(mylist, ptr);
	mylist.printList();
	return 1;
}

