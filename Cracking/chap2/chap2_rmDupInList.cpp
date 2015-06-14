/*
* Write code to remove duplicates from an unsorted linked list. 
* FOLLOW UP How would you solve this problem if a temporary buffer is not allowed?
*/

#include <iostream>
#include"myList.h"
#include <set>

using namespace std;

//Remove Dup with buffer, use set as the buffer

//This is O(n) space, O(n) time

void myList::rmDup_v1()
{
	set<int> dataset;
	Node* cur = head;
	while (cur != NULL){
		if (!dataset.count(cur->value)){
			dataset.insert(cur->value);
		}
		else{
			//Remove this node
			cur=rmNode(cur);
		}
		cur = cur->next;
	}
}

//Another solution: loop from beginning
//Time: O(n^2), space O(1)
void myList::rmDup()
{
	Node* cur=head;
	Node* scan = head->next;
	//scan is used to scan the following elements to check
	while (cur != NULL){
		int curVal = cur->value;
		scan = cur->next;
		while (scan != NULL){
			if (scan->value == curVal)
				scan = this->rmNode(scan);
			else
				scan = scan->next;
		}
		cur = cur->next;
	}
}

int main()
{
	myList mylist;
	mylist.push_back(0); mylist.push_back(1); mylist.push_back(2);
	mylist.push_back(3); mylist.push_back(1); mylist.push_back(4);
	mylist.push_back(5); mylist.push_back(2); mylist.push_back(7);
	mylist.push_back(8); mylist.push_back(2); mylist.push_back(9);
	mylist.printList();
	mylist.rmDup();
	mylist.printList();


	return 0;
}



