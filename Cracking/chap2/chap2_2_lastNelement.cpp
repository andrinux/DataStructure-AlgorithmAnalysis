/*
* Implement an algorithm to find the nth to last element of a singly linked list.
*/

#include <iostream>
#include"myList.h"
#include <stdlib.h>

//If we don't use refrence here, VS2012 will cause memory bug.
//This method will seek for twice, not the optimal
void last_N_element_1(const myList& my, int n){
	int sz = 0;
	Node* cur = my.head;
	while (cur!=NULL){
		sz++;
		cur = cur->next;
	}
	if (n > sz){
		std::cout << "Error occur" << std::endl;
		return;
	}
	cur = my.head;
	int idx = 0;
	while (cur != NULL){
		if (idx >= (sz - n)){
			std::cout << cur->value << "-";
		}
		idx++;
		cur = cur->next;
	}
	return;
}
/*use FAST-SLOW pointers*/
//Time O(n) as well.
void last_N_element(const myList& my, int n){
	Node* pt1 = my.head;
	Node* pt2 = my.head;
	for (int i = 0; i < n; i++)
		pt2 = pt2->next;
	while (pt2 != NULL){
		pt1 = pt1->next;
		pt2 = pt2->next;
	}
	std::cout << pt1->value << std::endl;
}

void main()
{
	myList mylist;
	mylist.push_back(0); mylist.push_back(1); mylist.push_back(2);
	mylist.push_back(3); mylist.push_back(1); mylist.push_back(4);
	mylist.push_back(5); mylist.push_back(2); mylist.push_back(7);
	mylist.push_back(8); mylist.push_back(2); mylist.push_back(9);
	mylist.printList();

	last_N_element(mylist, 4);

}
