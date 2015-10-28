// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 28-10-2015

/********************************************************************************** 
* Given a sorted linked list, delete all duplicates such that each element appear only once.
* For example,
* Given 1->1->2, return 1->2.
* Given 1->1->2->3->3, return 1->2->3.
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
		ListNode *a = head;

		while(a->next != NULL){
			int v1 = a->val;
			int v2 = a->next->val;
			if(v1 == v2){
				a->next = a->next->next;
			}
			else{
				a = a->next;
			}
		}
		return head;
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
