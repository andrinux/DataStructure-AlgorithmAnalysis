#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || k<=0) return head;
		ListNode* p = head;
		int Len = 0;
		while (p){
			Len++;
			p = p->next;
		}
		//get the length of this list.
		k = k%Len;
		//begin to work
		ListNode* p1 = head;
		ListNode* p2 = head;
		for (int i = 0; i < k; i++)
			p2 = p2->next;
		//Two pointers chasing.
		while (p2->next != NULL){
			p1 = p1->next;
			p2 = p2->next;
		}
		//Store the return value
		ListNode* newhead = (p1->next==NULL)?head:p1->next;
		//Now p2 is at the end.
		p2->next = head;
		p1->next = NULL;
		return newhead;
	}
};

int main()
{
	ListNode * head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);

	ListNode *p = head;
	while (p != NULL){
		cout << p->val << " -> ";
		p = p->next;
	}
	cout << endl;

	Solution so;
	p = so.rotateRight(head, 6);

	while (p != NULL){
		cout << p->val << " -> ";
		p = p->next;
	}

	return 1;
}
