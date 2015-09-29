// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 29-09-2015

/********************************************************************************** 
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* Each element in the array represents your maximum jump length at that position. 
* Determine if you are able to reach the last index.
* For example:
* A = [2,3,1,1,4], return true.
* A = [3,2,1,0,4], return false.
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;


/*
idea: greedy alogrithm.
for every node: count the max length of next step
for node > last maximum: judge if fail or not->add one step and move forward
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
    int n = nums.size();
		if(n<0) return false;
		int next=0;
		int last=0;
		for(int i=0; i<n; i++){
			if(i>last){
				if(last == next && last <n-1) return false;
				last = next;
			}
			next = max(next, i+nums[i]);
		}
		return true;
    }
};

/* //For testing
int main(){
    Solution test;
	int arr[] = {2,3,1,1,4};
	int arr2[]= {3,2,1,0,4};
	vector<int> v;
	v.assign(arr,arr+5);
	cout << test.canJump(v) << endl;
	v.clear();
	v.assign(arr2,arr2+5);
	cout << test.canJump(v) << endl;
    return 0;
}
*/
