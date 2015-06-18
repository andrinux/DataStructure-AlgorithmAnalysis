/*
* Check if a list is a palindrome.
*/

#include <iostream>
#include "myList.h"
#include <stack>

//Push the first half of list into stack
//Pop and check. How to find the middle Node
bool palindrome_v1(Node *& head){
	std::stack<int> data;
	Node *fast = head;
	Node *slow = head;

	while(fast!=NULL && fast->next != NULL){
		data.push(slow->value);
		fast = fast->next->next;
		slow = slow->next;
	}
	//Skip the middle point if odd number length
	if(fast!=NULL && fast->next == NULL)
		slow=slow->next;

	while(slow != NULL){
		if(slow->value == data.top()){
			data.pop();
			slow = slow->next;
		}else{
			return false;
		}
	}
	return true;
}

bool do_Palindrome(Node *head, int length){
	//Base case

}
//Recursion Version of Palindrome Checking
//It seems we need to get the tail?
bool palindrome_vR(Node *& head){
	int length;
	do_Palindrome(head, length);

}

int  main()
{
	myList mylist;
	mylist.push_back(1); mylist.push_back(6); mylist.push_back(2);
	mylist.push_back(3); mylist.push_back(7); /*mylist.push_back(4);
	mylist.push_back(4); */mylist.push_back(7); mylist.push_back(3);
	mylist.push_back(2); mylist.push_back(6); mylist.push_back(1);
	mylist.printList();
	
	bool res=palindrome_vR(mylist.head);
	if(res)
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;
	
	return 1;
}