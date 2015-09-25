#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void genListFromVec(ListNode *&head, vector<int> nums){
	if (nums.size() == 0)
		head = NULL;
	ListNode *newhead = new ListNode(-1);
	head = newhead;
	for (int i = 0; i < nums.size(); i++){
		newhead->next = new ListNode(nums[i]);
		newhead = newhead->next;
	}
	newhead->next = NULL;
	newhead = head;
	head = head->next;
	delete newhead;

}

// A much concise solution : http://www.cnblogs.com/lichen782/p/leetcode_Reverse_Nodes_in_kGroup.html

class Solution {
public:
	//Reverse a list between begin and end.
	void ReverseK(ListNode *begin, ListNode *end){
		ListNode * prev = begin->next;
		ListNode * cur = prev->next;
		ListNode * tmp = cur->next;
		while (cur != end){
			cur->next = prev;
			prev = cur;
			cur = tmp;
			tmp = cur? cur->next : NULL; //seems ugly.
		}
		begin->next->next = end;
		begin->next = prev;
	}
	//show list.
	void show(ListNode *head){
		while (head){
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
	}
	//Easy to get bug.
	//(Bug1). failed to reset begin.
	//(Bug2). when k=size. need to reverse as well.
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k <= 1)
			return head;
		ListNode newhead(-1);
		ListNode * begin = &newhead;
		begin->next = head;//link
		ListNode * end = begin->next;
		ListNode * tmp = begin->next;
		//
		while (end != NULL){
			for (int i = 0; i < k; i++){
				end = end->next;
				if (end == NULL && i < k - 1)
					return newhead.next;
			}
			tmp = begin->next;
			ReverseK(begin, end);
			//Reset begin, begin should be last node before the range.
			begin = tmp;
		}
		return newhead.next;
		
	}
};


int main()
{
	vector<int> num = { 1,2 };
	ListNode * p = NULL;
	genListFromVec(p, num);
	Solution so;
	p = so.reverseKGroup(p, 2);
	while (p){
		cout << p->val << "->";
		p = p->next;
	}
	return 1;
}