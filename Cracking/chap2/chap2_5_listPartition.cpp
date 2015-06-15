/*
* Write code to partition a linked list around a value x, 
* such that all nodes less than x come before all nodes greater than or equal to x.
*/

#include <iostream>
#include "myList.h"
//Question: x is unique?

//Version-1: Space O(n), time O(n)
void partitionList_v1(myList& my, int x){
	myList res1, res2;
	Node *p1 = NULL;
	Node *p = my.head;
	while (p != NULL){
		if (p->value < x){
			res1.push_back(p->value);
			if (p1 == NULL)
				p1 = res1.head;
			else
				p1 = p1->next;
		}
		else{
			res2.push_back(p->value);
		}
		p = p->next;
	}
}

//version-2: Space O(1), time O(n^2)
void partitionList_v2(myList& my, int x){

}


int  main()
{
	myList mylist;
	mylist.push_back(0); mylist.push_back(6); mylist.push_back(2);
	mylist.push_back(3); mylist.push_back(7); mylist.push_back(4);
	mylist.push_back(5); mylist.push_back(2); mylist.push_back(7);
	mylist.push_back(1); mylist.push_back(2); mylist.push_back(9);
	mylist.printList();
	myList newlist(mylist);
	partitionList_v1(mylist, 5);
	mylist.printList();
	//Another
	partitionList_v2(newlist, 5);
	newlist.printList();
	return 1;
}