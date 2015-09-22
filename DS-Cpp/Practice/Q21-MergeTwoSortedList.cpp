#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
	ListNode* mergeTwoLists(ListNode* p1, ListNode* p2) {
		ListNode *p = new ListNode(-1); 
		ListNode *newhead = p;
		if (p1 == NULL && p2 == NULL)
			return NULL;
		ListNode * tmp = NULL;
		while (p1 != NULL && p2 != NULL){
			if (p1->val <= p2->val){
				tmp = p1->next;
				p->next = p1;
				p1 = tmp;
			}
			else{
				tmp = p2->next;
				p->next = p2;
				p2 = tmp;
			}
			p = p->next;
		}
		//At least one is end.
		if (p1 == NULL && p2 == NULL)
			p->next = NULL;
		else if (p1 == NULL &&p2 != NULL)
			p->next = p2;
		else
			p->next = p1;

		return newhead->next;
	}
};
 
int main()
{
	ListNode * p1 = new ListNode(1);
	p1->next = new ListNode(3);
	p1->next->next = new ListNode(5);
	p1->next->next->next = new ListNode(7);
	p1->next->next->next->next = new ListNode(9);


	ListNode * p2 = new ListNode(2);
	p2->next = new ListNode(4);
	p2->next->next = new ListNode(6);
	p2->next->next->next = new ListNode(8);
	p2->next->next->next->next = new ListNode(10);
	p2->next->next->next->next->next = new ListNode(12);

	Solution so;
	ListNode *p;
	p = so.mergeTwoLists(p1, p2);
	while (p != NULL){
		cout << p->val << " - ";
		p = p->next;
	}
	return 1;
}