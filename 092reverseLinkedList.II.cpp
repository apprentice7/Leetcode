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
