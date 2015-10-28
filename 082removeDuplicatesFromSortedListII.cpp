// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 28-10-2015

/********************************************************************************** 
* Given a sorted linked list, delete all nodes that have duplicate numbers, 
* leaving only distinct numbers from the original list.
* For example,
* Given 1->2->3->3->4->4->5, return 1->2->5.
* Given 1->1->1->2->3, return 2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
		if(head == NULL) return head;
		ListNode *a = new ListNode(0);
		ListNode *output = a;
		a->next = head;
		int temp = head->val-1;

		while(a->next->next != NULL){
			int v1 = a->next->val;
			int v2 = a->next->next->val;
			if(v1 == v2 || v1 == temp){
				a->next = a->next->next;
				temp = v1;
			}
			else{
				a = a->next;
			}
		}
		if(a->next->val == temp) a->next = a->next->next;
		output = output->next;
		return output;
    }
};

/* //For testing
int main(){
	Solution test;
	ListNode *p;
	ListNode *a = new ListNode(1);
	p = a;
	a->next = new ListNode(1);
	a = a->next;
	a->next = new ListNode(2);
	a = a->next;
	a->next = new ListNode(3);
	a = a->next;
	a->next = new ListNode(4);
	a = a->next;
	a->next = new ListNode(4);

	ListNode *re = test.deleteDuplicates(p);
	while(re != NULL){
		cout<<re->val<<endl;
		re = re->next;
	}
	return 0;
}
*/
