// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 25-08-2015

/********************************************************************************** 
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
* If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
* You may not alter the values in the nodes, only nodes itself may be changed.
* Only constant memory is allowed.
* For example,
* Given this linked list: 1->2->3->4->5
* For k = 2, you should return: 2->1->4->3->5
* For k = 3, you should return: 3->2->1->4->5
**********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
	ListNode* reverseKGroup(ListNode* head, int k){
		if(head == NULL || head->next == NULL) return head;
		if(k <= 1) return head;
		
		ListNode* p1 = head;
		
		ListNode* Output = new ListNode(0);
		Output = Swap(p1,k);
		return Output;
	}
	ListNode* Swap(ListNode* p1,int k){
		ListNode* test = p1;
		if(p1 == NULL) return NULL;
		bool flag = true;
		for(int i=0; i<k; i++){
			if(test == NULL){
				flag = false;
				break;
			}
			test = test->next;
		}
		if(flag == false) return p1;
		else{
			ListNode* head1 = p1;
			ListNode* tail1 = p1->next;
			ListNode* temp = new ListNode(0);
			for(int t=0; t<k-1; t++){
				temp = tail1->next;
				tail1->next = head1;
				head1 = tail1;
				tail1 = temp;
			}
			p1->next = Swap(tail1,k);
			return head1;
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
	Node1->next = Node2;
	Node2->next = Node3;
	Node3->next = Node4;
	Node4->next = Node5;
	Node5->next = Node6;

	ListNode* result = test.reverseKGroup(Node1,4);
	while(result != NULL){
		cout << result->val << endl;
		result = result->next;
	}
	return 0;
}
*/
