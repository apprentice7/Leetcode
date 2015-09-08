// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 08-09-2015

/**********************************************************************************
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* You are given a target value to search. If found in the array return its index, otherwise return -1.
* You may assume no duplicate exists in the array.             
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
		if(n<1) return -1;

		if(target > nums[0]){
			for(int i=1; i<n; i++){
				if(target == nums[i]) return i;
				else if(nums[i] < nums[i-1]) return -1;
			}
		}
		else if(target == nums[0]) return 0;
		else{
			int i = 1;
			while(nums[i] > nums[i-1]){
				i++;
			}
			for(; i<n; i++){
				if(nums[i] == target) return i;
			}
		}
		return -1;
    }
};

/* //For testing
int main(){
	Solution test;
	int arr[] = {4,5,6,7,0,1,2};
	vector<int> v;
	v.assign(arr,arr+7);
	cout << test.search(v,1) << endl;

	return 0;
}
*/
