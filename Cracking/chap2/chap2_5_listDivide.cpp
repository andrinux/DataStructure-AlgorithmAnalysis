//Divide a list based on a given value. Smaller on the left, Large on the right. 
//It is possible that the given value is not unique.
//all nodes less than x come before all nodes greater than or equal to x.


#include <iostream>
#include "myList.h"

void listDivide(myList &my, int val){
	//Special cases
	if (my.head == NULL)
		return;
	//start from the second node in the list
	Node *p = my.head;
	Node *pre = NULL;
	Node *next = p->next;
	while (p != NULL){
		//skip head.
		if (p->value >= val || p == my.head){
			pre = p;
			p = next;
			next = (p!=NULL)?p->next:NULL;
		}
		else{
			//rm
			pre->next = next;
			//move
			p->next = my.head;
			my.head = p;
			//reset
			p = next;
			next = (p != NULL) ? p->next : NULL;
		}
	}
	return;
}

int main()
{
	myList mylist;
	mylist.push_back(0); mylist.push_back(6); mylist.push_back(2);
	mylist.push_back(3); mylist.push_back(7); mylist.push_back(4);
	mylist.push_back(5); mylist.push_back(2); mylist.push_back(7);
	mylist.push_back(1); mylist.push_back(2); mylist.push_back(9);
	mylist.push_back(10); mylist.push_back(2);
	mylist.printList();
	listDivide(mylist, 0);
	mylist.printList();
	return 0;
}