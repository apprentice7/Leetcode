// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 04-11-2015

/********************************************************************************** 
* Given a linked list and a value x, partition it such that all nodes less than x come 
* before nodes greater than or equal to x.
* You should preserve the original relative order of the nodes in each of the two partitions.
* For example,
* Given 1->4->3->2->5->2 and x = 3,
* return 1->2->2->4->3->5.
**********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        //append node to process head
		ListNode * start = new ListNode(0);
		start->next = head;

		ListNode * tmp = start;
		ListNode * pos = start;

		while(tmp->next != NULL){
			if(tmp->next->val < x){
				if(pos == tmp) {
					pos = pos->next;
					tmp = tmp->next;
				}
				else{
					ListNode* tmpNext = tmp->next->next;
					ListNode* posNext = pos->next;
					//insert element into pos
					pos->next = tmp->next;
					pos->next->next = posNext;
					pos = pos->next;
					//delete element from tmp
					tmp->next = tmpNext;
					if(tmpNext == NULL) break;
				}
			}
			else{
				tmp = tmp->next;
			}
		}
		start = start->next;
		return start;
    }
};

/* //For testing
int main(){
	Solution test;
	ListNode *a = new ListNode(3);
	ListNode *head = a;
	a->next = new ListNode(2);
	a= a->next;
	a->next = new ListNode(11);
	a= a->next;
	a->next = new ListNode(5);
	a= a->next;
	a->next = new ListNode(0);
	a= a->next;
	a->next = new ListNode(12);
	a= a->next;

	a = test.partition(head, 10);
	while(a != NULL){
		cout<<a->val <<endl;
		a = a->next;
	}
	return 0;
}
*/
