#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



// Three Solutions:
// (1)- Brute force. (2) Divide and Conquer (3) Make Heaps
class Solution {
public:
	void showList(ListNode* p){
		if (p == NULL)
			cout << "This is NULL list." << endl;
		while (p != NULL){
			cout << p->val << " - ";
			p = p->next;
		}
		cout << endl;
	}
	/*
	*
	*                 Method (1):Divide and Conquer.
	*                  Complexity is O(nklogk)
	*
	*/
	ListNode* mergeKLists_1(vector<ListNode*>& lists) {
		//corner cases.
		if (lists.size() == 0)
			return NULL;
		//make the size even
		if (lists.size() % 2 == 1)
			lists.push_back(NULL);
		int N = lists.size(); //current list count
		while (N > 1){
			for (int i = 0; i < N / 2; i++){
				//merge two lists
				ListNode* L1 = lists[2 * i];
				ListNode* L2 = lists[2 * i + 1];
				ListNode* p = new ListNode(-1);
				ListNode* backup = p;
				while (L1 && L2){
					if (L1->val < L2->val){
						p->next = L1;
						L1 = L1->next;
					}
					else{
						p->next = L2;
						L2 = L2->next;
					}
					p = p->next;
				}
				p->next = (L1 == NULL) ? L2 : L1;
				lists[i] = backup->next;
				delete backup;
			}//Finish the N lists merging to N/2 lists
			for (int i = N / 2; i < N; i++)
				lists[i] = NULL;
			//Make sure N is a even number or 1
			N = N / 2;
			if (N > 1 && N % 2 == 1)
				N = N + 1;
		}
		return lists[0];
	}





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


int main()
{
	ListNode *p1=NULL, *p2=NULL, *p3=NULL, *p4=NULL, *p5=NULL;
	vector<int> num;
	num = { 1, 5, 7,  9, 13};  genListFromVec(p1, num);
	num = { 2 ,6, 10,  19, 20};  genListFromVec(p2, num);
	num = { 3 , 11, 15};  genListFromVec(p3, num);
	num = {}; genListFromVec(p4, num);
	num = { 4, 8, 12, 14, 16, 17, 18};  genListFromVec(p5, num);
	
	vector<ListNode*> lists;
	lists.push_back(p1);
	lists.push_back(p2);
	lists.push_back(p3);
	lists.push_back(p4);
	lists.push_back(p5);
	Solution so;

	ListNode* p = NULL;
	p = so.mergeKLists(lists);
	while (p != NULL){
		cout << p->val << " - ";
		p = p->next;
	}


	//priority_queue<int> heap;
	//heap.push(5); heap.push(0); heap.push(12); heap.push(9);
	//while (heap.size() > 0){
	//	cout << heap.top();
	//	heap.pop();
	//}
	return 1;
}
