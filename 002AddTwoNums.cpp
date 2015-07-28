// Source : https://oj.leetcode.com/problems/add-two-numbers/
// Author : Tony
// Date   : 28-07-2015

/********************************************************************************** 
* 
* You are given two linked lists representing two non-negative numbers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
* 
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*               
**********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

typedef struct ListNode{
	int val;
	ListNode* next;
};
void initNode(struct ListNode* head, int n){
	head->val = n;
	head->next = NULL;
}
void addNode(struct ListNode *head, int n){
	ListNode *newNode = new ListNode;
	newNode->val = n;
	newNode->next = NULL;
	ListNode *cur = head;
	while(cur){
		if(cur->next == NULL){
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

class Solution{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
		ListNode* results = new ListNode;
	int a,b,c;
	a = (l1->val+l2->val) % 10;
	initNode(results, a);
	b = ((l1->val+l2->val)/10 + l1->next->val + l2->next->val) % 10;
	addNode(results, b);
	c = (((l1->val+l2->val)/10 + l1->next->val + l2->next->val)/10 + l1->next->next->val + l2->next->next->val) % 10;
	addNode(results, c);
	
	return results;
	}
};

/* For testing 
int main(){
	ListNode *LN1 = new ListNode;
	ListNode *LN2 = new ListNode;
	ListNode *head = new ListNode;
	initNode(LN1,2);
	addNode(LN1,4);
	addNode(LN1,3);
	initNode(LN2,5);
	addNode(LN2,6);
	addNode(LN2,4);
	
	Solution solution;
	head = solution.addTwoNumbers(LN1, LN2);

	cout << "val 1: " << head->val << endl;
	cout << "val 2: " << head->next->val << endl;
	cout << "val 3: " << head->next->next->val << endl;
	return 0;
}
*/
