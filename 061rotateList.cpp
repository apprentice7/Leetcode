// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 02-10-2015

/********************************************************************************** 
* Given a list, rotate the list to the right by k places, where k is non-negative.
* For example:
* Given 1->2->3->4->5->NULL and k = 2,
* return 4->5->1->2->3->NULL.
**********************************************************************************/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    ListNode* tempHead = head;
		if(head == NULL) return head;
		int size = 1;
		int i=0;

		while(tempHead->next != NULL){
			tempHead = tempHead->next;
			size++;
		}
		tempHead->next = head;
		while(i < (size-k%size)){
			head = head->next;
			tempHead = tempHead->next;
			i++;
		}
		tempHead->next = NULL;
		return head;
    }
};

/* //For testing
int main(){
    Solution test;
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);
	
	ListNode *head = node1;
	ListNode *re;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	ListNode* tempH = head;
	while(head != NULL){
		cout<< head->val << endl;
		head = head->next;
	}
	cout << endl;

	re = test.rotateRight(tempH, 6);
	while(re != NULL){
		cout<< re->val << endl;
		re = re->next;
	}

    return 0;
}
*/
