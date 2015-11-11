// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 11-11-2015

/********************************************************************************** 
* Reverse a linked list from position m to n. Do it in-place and in one-pass.
* For example:
* Given 1->2->3->4->5->NULL, m = 2 and n = 4,
* return 1->4->3->2->5->NULL.
* Note:
* Given m, n satisfy the following condition:
* 1 ≤ m ≤ n ≤ length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	ListNode* current = head;
	ListNode* rear = new ListNode(0);
	rear->next = head;
	ListNode* front = head;
	ListNode* output = rear;
	int iter = m;
	int i = 0;
		
	while(iter > 1){
		rear = rear->next;
		iter--;
	}
	current = rear->next;
	front = current->next;
		
	while(i<n-m){
		current->next = front->next;
		front->next = rear->next;
		rear->next = front;
		front = current->next;
		i++;
	}
	return output->next;
    }
};

/* //For testing
int main(){
	Solution test;	
	ListNode *a = new ListNode(1);
	ListNode *b = a;
	a->next = new ListNode(2);
	a = a->next;
	a->next = new ListNode(3);
	a = a->next;
	a->next = new ListNode(4);
	a = a->next;
	a->next = new ListNode(5);
	a = test.reverseBetween(b, 5, 5);

	while(a != NULL){
		cout << a->val << " ";
		a = a->next;
	}
	cout << endl;
	return 0;
}
*/
