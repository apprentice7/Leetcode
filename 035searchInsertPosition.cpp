// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 09-09-2015

/********************************************************************************** 
* Given a sorted array and a target value, return the index if the target is found. 
* If not, return the index where it would be if it were inserted in order.
* You may assume no duplicates in the array.
* Here are few examples.
* [1,3,5,6], 5 → 2
* [1,3,5,6], 2 → 1
* [1,3,5,6], 7 → 4
* [1,3,5,6], 0 → 0            
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
		if(n<1) return -1;
		int Upper = n-1;
		int Lower = 0;
		int i=-1;

		while(Lower <= Upper){
			i = (Upper+Lower)/2;
			if(target == nums[i]) return i;
			else{
				if(target > nums[i]){
					Lower = i+1;
				}
				else{
					Upper = i-1;
				}
			}
		}
		return Lower;
    }
};

/* //For testing
int main(){
	Solution test;
	int arr[] = {1,3,5,6};
	vector<int> v;
	v.assign(arr,arr+4);
	cout << test.searchInsert(v,0) << endl;

	return 0;
}
*/
