// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 21-08-2015

/********************************************************************************** 
* Given a linked list, remove the nth node from the end of list and return its head.
* For example,
*    Given linked list: 1->2->3->4->5, and n = 2.
*    After removing the second node from the end, the linked list becomes 1->2->3->5.
* Note:
* Given n will always be valid.
* Try to do this in one pass.             
**********************************************************************************/


#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

typedef struct ListNode{
	int val;
	ListNode* next;
	//ListNode(int x) : val(x), next(NULL){}
}ListNode;

ListNode* initNode(struct ListNode* head, int n){
	head->val = n;
	head->next = NULL;
	return head;
}

ListNode* addNode(struct ListNode *head, int n){
	ListNode *newNode = new ListNode;
	newNode->val = n;
	newNode->next = NULL;
	ListNode *cur = head;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = newNode;
	return head;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL || n<=0 ){
            return NULL;
        }
        ListNode NewHead;
        NewHead.next=head;
        head=&NewHead;
        
        ListNode *p1, *p2;
        p1=p2=head;
        for(int i=0; i<n; i++){
            if (p2==NULL) return NULL;
            p2=p2->next;
        }
        while (p2->next!=NULL){
            p2=p2->next;
            p1=p1->next;
        }
        p1->next = p1->next->next;
        return head->next;
    }
};

/* //For testing
int main(){
	ListNode *LN1 = new ListNode;
	ListNode *head = new ListNode;
	initNode(LN1,1);
	addNode(LN1,2);
	addNode(LN1,3);
	addNode(LN1,4);
	addNode(LN1,5);
	Solution solution;
	head = solution.removeNthFromEnd(LN1,2);
	while(head != NULL){
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}
*/
