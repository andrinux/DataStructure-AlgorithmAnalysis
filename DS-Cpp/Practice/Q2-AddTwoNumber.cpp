/**
 Definition for singly-linked list.
 **/
#include <iostream>
#include <vector>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode *p1=l1, *p2=l2;
    ListNode *res = NULL, *head = NULL;
    //edge cases

    while(p1!=NULL || p2!=NULL ||carry != 0){
        
        int num1 =(p1==NULL) ? 0 : p1->val;
        int num2 =(p2==NULL) ? 0 : p2->val;
        
        int cur = num1 + num2 + carry;

        carry = cur/10;

        if(res == NULL){
            res = new ListNode(cur%10);
            head = res;
        }
        else{
            res->next = new ListNode(cur%10);
            res=res->next;//indicate the current position.
        }
            
        //After read solution@ https://leetcode.com/discuss/2308/is-this-algorithm-optimal-or-what
        //This two lines can be combined
        p1 = (p1==NULL) ? NULL: p1->next;
        p2 = (p2==NULL) ? NULL: p2->next;
    }
    //output res list:
    //res = head;

    //****************
    //The printing will cost a lot of time! BECAUSE of ITS IO
    //Can be removed for submission.
    //***************

    //while(res != NULL){
    //    cout << res->val;
    //    if(res->next != NULL)
    //        cout << " -> ";
    //    res = res->next;
    //}
    //Do we need to free memory
    return head;
}
};

int main()
{
    ListNode* Num1;
    ListNode* Num2;
    Num1= new ListNode(2);
    Num1->next = new ListNode(4);
    Num1->next->next = new ListNode(3);

    Num2 = new ListNode(5);
    Num2->next= new ListNode(6);
    Num2->next->next = new ListNode(4);

    Solution so;
    ListNode *res;
    res = so.addTwoNumbers(Num1, Num2);

    while(res != NULL){
        cout << res->val;
        if(res->next != NULL)
            cout << " -> ";
        res = res->next;
    }
    //Do we need to free memory?

    return 1;
}