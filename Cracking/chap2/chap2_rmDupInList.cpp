/*
* Write code to remove duplicates from an unsorted linked list. 
* FOLLOW UP How would you solve this problem if a temporary buffer is not allowed?
*/

#include <iostream>
#include"myList.h"
#include <set>

using namespace std;

//Remove Dup with buffer
void myList::rmDup()
{
	set<int> dataset;
	Node* cur = head;
	while (cur != NULL){
		if (!dataset.count(cur->value)){
			dataset.insert(cur->value);
		}
		else{
			//Remove this node
			cur=this->rmNode(cur);
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
	mylist.printList();
	mylist.rmDup();
	mylist.printList();
	

	return 0;
}



