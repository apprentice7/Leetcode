// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 24-08-2015

/********************************************************************************** 
* Given a linked list, swap every two adjacent nodes and return its head.
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
* Your algorithm should use only constant space. You may not modify the values in the list, 
* only nodes itself can be changed.
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
	ListNode* swapPairs(ListNode* head){
		if(head == NULL || head->next == NULL) return head;
		ListNode* p1 = head;
		ListNode* p2 = head->next;
		ListNode* Output = new ListNode(0);
		Output = Swap(p1,p2);
		return Output;
	}
	ListNode* Swap(ListNode* p1, ListNode* p2){
		ListNode* Newp1 = p1->next->next;
		if(Newp1 == NULL){
			p2->next = p1;
			p1->next = NULL;
			return p2;
		}
		else{
			ListNode* Newp2 = p2->next->next;
			if(Newp2 == NULL){
				p2->next = p1;
				p1->next = Newp1;
				return p2;
			}
			else{
				p2->next = p1;
				p1->next = Swap(Newp1,Newp2);
				return p2;
			}
		}
	}
};

/* //For testing
int main(){
	Solution test;
	ListNode* Node1 = new ListNode(1);
	ListNode* Node2 = new ListNode(2);
	ListNode* Node3 = new ListNode(3);
	ListNode* Node4 = new ListNode(4);
	ListNode* Node5 = new ListNode(5);
	ListNode* Node6 = new ListNode(6);
	ListNode* Node7 = new ListNode(7);
	Node1->next = Node2;
	Node2->next = Node3;
	Node3->next = Node4;
	Node4->next = Node5;
	Node5->next = Node6;
	Node6->next = Node7;

	ListNode* result = test.swapPairs(Node1);
	while(result != NULL){
		cout << result->val << endl;
		result = result->next;
	}


	return 0;
}
*/
