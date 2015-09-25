// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 25-09-2015

/********************************************************************************** 
* Find the contiguous subarray within an array (containing at least one number) 
* which has the largest sum.
* For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
* the contiguous subarray [4,−1,2,1] has the largest sum = 6.
* More practice:
* If you have figured out the O(n) solution, try coding another solution using 
* the divide and conquer approach, which is more subtle.
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

/*
idea: Kadane's Algorithm
https://en.wikipedia.org/wiki/Maximum_subarray_problem
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
		int lgsum=nums[0];
		for(int i=1;i<nums.size();i++){
		    sum=max(nums[i],sum+nums[i]);
		    lgsum=max(lgsum,sum);
		}
		return lgsum;
	}
};

/* //For testing
int main(){
	Solution test;
	int arr[]={-2,1,-3,4,-1,2,1,-5,4};
	vector<int> v;
	v.assign(arr,arr+9);
	cout<< test.maxSubArray(v) << endl;
	return 0;
}
*/
