/*
* You have two numbers represented by a linked list, where each node contains a single digit. 
* The digits are stored in reverse order, such that the 1¡¯s digit is at the head of the list. 
* Write a function that adds the two numbers and returns the sum as a linked list.
* EXAMPLE
* Input: (3 -> 1 -> 5), (5 -> 9 -> 2)
* Output: 8 -> 0 -> 8

* FOLLOW UP: in forward order: Output: (9 -> 0 -> 7)
*/

#include <iostream>
#include "myList.h"
#include <vector>
#include <stack>

//Reverse the single linked list
void reverseList(const myList& my, myList& res){
	std::vector<int> numbers;
	Node *ptr = my.head;
	while (ptr != NULL){
		numbers.push_back(ptr->value);
		ptr = ptr->next;
	}
	res.destroyList(res.head);
	for (int i = numbers.size() - 1; i >= 0; i--){
		res.push_back(numbers[i]);
	}
}

//Note that the length of num1&2 may be different.
//I think this is pretty clear to understand.
void addList(const myList&  num1, const myList& num2, myList& sum, int& carry){
	Node* p1 = num1.head;
	Node* p2 = num2.head;
	while (p1 != NULL || p2 != NULL){
		int d1 = (p1 == NULL) ? 0 : p1->value;
		int d2 = (p2 == NULL) ? 0 : p2->value;
		int d = d1 + d2 + carry;
		if (d >= 10){
			d = d - 10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		sum.push_back(d);
		//Don't forget
		p1 = (p1 == NULL) ? NULL : p1->next;
		p2 = (p2 == NULL) ? NULL : p2->next;
	}
	if (carry)
		sum.push_back(1);
}

//If the digits are listed in forward order
//NOTE: This is for single-linked-list, not doubly linked list
//(1): O(n^2) method is to rm the last node after calculation each time;<-- not good.
//(2): use array to store the results. trace back to fix each time O(n^2) worst
//(3): reverse the list first, and then 
//(4): Use stack to store the numbers.
void addListFrd(const myList& num1, const myList& num2, myList& frd, int& carry){
	carry = 0;
	myList n1, n2, sum;
	reverseList(num1, n1);
	reverseList(num2, n2);
	addList(n1, n2, sum, carry);
	reverseList(sum, frd);
}

//A straightforward way, not to reverse the single list
void addListFrd_array(const myList& num1, const myList& num2, myList& frd, int& carry){
	std::stack<int> n1, n2, s;
	carry = 0;
	Node* p1 = num1.head;
	Node* p2 = num2.head;
	while (p1 != NULL){
		n1.push(p1->value);
		p1 = p1->next;
	}
		
	while (p2 != NULL){
		n2.push(p2->value);
		p2 = p2->next;
	}
		
	while (n1.size() || n2.size()){
		int d1 = (n1.size() == 0) ? 0 : n1.top(); n1.pop();
		int d2 = (n2.size() == 0) ? 0 : n2.top(); n2.pop();
		int d = d1 + d2 + carry;
		if (d >= 10){
			d = d - 10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		s.push(d);
	}
	if (carry)
		s.push(1);
	while (s.size()){
		frd.push_back(s.top());
		s.pop();
	}
}


int  main()
{
	myList num1, num2, sum, frd, frd_1;
	int carry=0;
	num1.push_back(3); num1.push_back(1); num1.push_back(5); 
	num2.push_back(5); num2.push_back(9); num2.push_back(2); 
	//myList test(num1);
	//test.printList();
	addList(num1, num2, sum, carry);
	sum.printList();
	addListFrd(num1, num2, frd, carry);
	frd.printList();
	addListFrd_array(num1, num2, frd_1, carry);
	frd_1.printList();
	return 1;
}

