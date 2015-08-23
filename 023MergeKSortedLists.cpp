// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 23-08-2015

/********************************************************************************** 
* Merge K sorted linked lists and return it as a new list. 
* Analyze and describe its complexity.
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
}ListNode;
ListNode* InitNode(ListNode* head, int v){
    head->val = v;
    head->next = NULL;
    return head;
}
ListNode* AddNode(ListNode* head, int v){
    ListNode* PtrToNode = new ListNode(0);
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* MergedList = new ListNode(0);
        //ListNode* OutList;
        int n = lists.size();
        if(n<1) return MergedList;
        if(n<2) return lists[0];
        MergedList = mergeTwoLists(lists[0], lists[1]);
        for(int i=2; i<n; i++){
            MergedList = mergeTwoLists(MergedList,lists[i]);    
        }
        return MergedList;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* output = new ListNode(0);
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
};

/* //For testing
int main(){
    ListNode *LN1 = new ListNode(0);
    ListNode *LN2 = new ListNode(0);
    ListNode *LN3 = new ListNode(0);
    ListNode *LN4 = new ListNode(0);
    ListNode *head = new ListNode(0);
    InitNode(LN1,1);
    AddNode(LN1,9);
    AddNode(LN1,13);
    AddNode(LN1,20);
    
    InitNode(LN2,0);
    AddNode(LN2,6);
    
    InitNode(LN3,10);
    AddNode(LN3,11);

    InitNode(LN4,8);
    AddNode(LN4,18);
    
    vector<ListNode*> v;
    v.push_back(LN1);
    v.push_back(LN2);
    v.push_back(LN3);
    v.push_back(LN4);
    Solution solution;
    head = solution.mergeKLists(v);
    while(head!=NULL){
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}
*/
