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
//Not clean enough! Need rewriting.
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode newhead(-1);
		ListNode *p = &newhead;
		p->next = head;
		ListNode *a = head, *b = head->next;
		ListNode *tmp = (b == NULL) ? NULL : b->next;
		// --- p -- a -- b -- tmp -- ---
		while (b && a ){
			p->next = b;
			b->next = a;
			a->next = tmp;
			//---
			if (tmp == NULL || tmp->next == NULL)
				break;
			p = a;
			a = tmp;
			b = tmp->next;
			tmp = b->next;
		}
		return newhead.next;
	}
};

int main()
{
	vector<int> num = { 4, 8, 12, 14, 16, 17 ,19};
	ListNode * p = NULL;
	genListFromVec(p, num);
	Solution so;
	p = so.swapPairs(p);
	while (p){
		cout << p->val << "->";
		p = p->next;
	}
}
