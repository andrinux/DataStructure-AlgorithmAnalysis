/*
* Implement an algorithm to find the nth to last element of a singly linked list.
*/

#include <iostream>
#include"myList.h"

void last_N_element(const myList my, int n){
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
	while (cur){
		if (idx >= (sz - n)){
			std::cout << cur->value << "-";
		}
		idx++;
		cur = cur->next;
	}
	return;
}

int main()
{
	myList mylist;
	mylist.push_back(0); mylist.push_back(1); mylist.push_back(2);
	mylist.push_back(3); mylist.push_back(1); mylist.push_back(4);
	mylist.push_back(5); mylist.push_back(2); mylist.push_back(7);
	mylist.push_back(8); mylist.push_back(2); mylist.push_back(9);
	mylist.printList();

	last_N_element(mylist, 4);
	return EXIT_SUCCESS;
}
