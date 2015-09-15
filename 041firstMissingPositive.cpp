// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 15-09-2015

/********************************************************************************** 
* Given an unsorted integer array, find the first missing positive integer.
* For example,
* Given [1,2,0] return 3,
* and [3,4,-1,1] return 2.
* Your algorithm should run in O(n) time and uses constant space.            
**********************************************************************************/

/*
In O(n) time and constant space, we need to sort this array.
The positive interger is our own target. And in O(n) time, we can
only go through every element by once.

Key point: put the positive number in the right position of the array.
i.e: put number 5 in nums[4], put number 1 in nums[0].
Omit the other numbers like negative integer or integer greater than the 
size of the array.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
		int digit=0;
		if(n<1) return 1;

		for(int i=0; i<n; i++){
			digit=nums[i];
			while(digit>0 && digit<n && nums[digit-1] != digit){
				swap(nums[digit-1], nums[i]);
				digit = nums[i];
			}
			/* //for testing
			for(int j=0; j<n; j++){
				cout << nums[j] << " ";
			}
			cout << endl;
			*/
		}
		for(int j=0; j<n; j++){
			if(nums[j] != j+1) return j+1;
		}
		return n+1;
    }
};
/* //For testing
int main(){
	Solution test;
	vector<int> v;
	int arr[] = {-1,4,2,1,9,10};
	v.assign(arr,arr+6);
	cout << test.firstMissingPositive(v) << endl;

	return 0;
}
*/
