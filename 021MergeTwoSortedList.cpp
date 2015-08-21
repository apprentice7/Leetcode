// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 22-08-2015

/********************************************************************************** 
* Merge two sorted linked lists and return it as a new list. The new list should be 
* made by splicing together the nodes of the first two lists.
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct ListNode{
	int val;
	ListNode *next;
	//ListNode(int x) : val(x), next(NULL){}
}ListNode;
ListNode* InitNode(ListNode* head, int v){
	head->val = v;
	head->next = NULL;
	return head;
}
ListNode* AddNode(ListNode* head, int v){
	ListNode* PtrToNode = new ListNode;
	PtrToNode->val = v;
	PtrToNode->next = NULL;
	ListNode* cur = head;

	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = PtrToNode;
	return head;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* output = new ListNode;
        if(p1->val <= p2->val){
        	output=InitNode(output, p1->val);
        	p1 = p1 -> next;
        }
        else{
        	output=InitNode(output,p2->val);
        	p2 = p2 -> next;
        }
        while(p1 != NULL){
        	if(p2 == NULL || p1->val <= p2->val){
        		output=AddNode(output,p1->val);
        		p1 = p1->next;
        	}
        	else{
        		output=AddNode(output,p2->val);
        		p2 = p2->next;
        		if(p2 == NULL){
        			while(p1!= NULL){
        				output=AddNode(output,p1->val);
        				p1 = p1->next;
        			}
        			return output;
        		}
        	}
        }
        while(p2!=NULL){
        	output=AddNode(output,p2->val);
        	p2 = p2->next;
        }
        return output;
    }
private:
	ListNode* InitNode(ListNode* head, int v){
		head->val = v;
		head->next = NULL;
		return head;
	}
	ListNode* AddNode(ListNode* head, int v){
		ListNode* PtrToNode = new ListNode;
		PtrToNode->val = v;
		PtrToNode->next = NULL;
		ListNode* cur = head;
		while(cur->next != NULL){
			cur = cur->next;
		}
		cur->next = PtrToNode;
		return head;
	}
};
/* //For testing
int main(){
	ListNode *LN1 = new ListNode;
	ListNode *LN2 = new ListNode;
	ListNode *head = new ListNode;
	InitNode(LN1,1);
	AddNode(LN1,2);
	AddNode(LN1,5);
	AddNode(LN1,7);
	//AddNode(LN1,9);
	InitNode(LN2,0);
	//AddNode(LN2,2);
	//AddNode(LN2,6);
	//AddNode(LN2,8);
	
	Solution solution;
	head = solution.mergeTwoLists(LN1, LN2);
	while(head!=NULL){
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}
*/
