#include <iostream>
#include <vector>
#include <algorithm>

// CODE is not that neat.

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
	ListNode* removeNthFromEnd_1(ListNode* head, int n) {
		//corner case.
		if (head == NULL || n < 1)
			return head;
		ListNode *p1 = head, *p2 = head;
		int i = 0;
		while (i < n){
			//n is very large.
			if (p2 == NULL)
				return head;
			p2 = p2->next;
			i++;
		}
		//move
		ListNode* p0;
		while (p2 != NULL){
			p2 = p2->next;
			p0 = p1;
			p1 = p1->next;
		}
		//now p1 directs to that Node.
		if (p1 == head){
			p0 = head->next;
			delete p1;
			return p0;
		}
		else{
			p0->next = p1->next;
			delete p1;
			return head;
		}
	}

	//Consider n is valid, So we no need to consider too many corner cases.
	ListNode* removeNthFromEnd(ListNode* head, int n){
		ListNode *fast = head, *slow = head;
		ListNode* p = NULL;
		if (head == NULL || n <= 0)
			return head;
		int i = 0;
		for (i = 0; i < n; i++)
			fast = fast->next;
		//corner case.
		if (fast == NULL){
			p = head->next;
			delete head;
			return p;
		}
		while (fast->next != NULL){
			fast = fast->next;
			slow = slow->next;
		}
		//Now slow->next is the node to be deleted.
		p = slow->next;
		slow->next = slow->next->next;
		delete p;
		return head;
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
	p = so.removeNthFromEnd(head, 6);
	
	while (p != NULL){
		cout << p->val << " -> ";
		p = p->next;
	}

	return 1;
}

