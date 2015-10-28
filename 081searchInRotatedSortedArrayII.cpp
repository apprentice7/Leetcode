// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 28-10-2015

/********************************************************************************** 
* Follow up for "Search in Rotated Sorted Array":
* What if duplicates are allowed?
* Would this affect the run-time complexity? How and why?
* Write a function to determine if a given target is in the array.
**********************************************************************************/

/* idea: https://leetcode.com/discuss/223/when-there-are-duplicates-the-worst-case-is-could-we-do-better
ans: time complexity will be O(n) in worst case like: 11111111...115 -> 5
binary search + determine left/right side is sorted
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
    int n = nums.size();
		int low = 0;
		int high = n-1;
		
		while(low <= high){
			int mid = (low+high)/2;
			if (nums[mid] == target) return true;
			else if(nums[low] < nums[mid]){ //left side is sorted
				if(nums[mid] > target && nums[low] <= target){
					high = mid-1;
				}
				else{
					low = mid+1;
				}
			}
			else if (nums[low] > nums[mid]){ //right side is sorted
				if(nums[mid]< target && nums[high] >= target){
					low = mid+1;
				}
				else{
					high = mid-1;
				}
			}
			else low++;
		}
		return false;
    }
};

/* //For testing
int main(){
	Solution test;
	int a[] = {2,2,3,4,5,5,5,1,1,1,1,1,2};
	vector<int> v;
	v.assign(a,a+13);
	cout<<test.search(v,1)<<endl;
	cout<<test.search(v,2)<<endl;
	cout<<test.search(v,4)<<endl;
	cout<<test.search(v,6)<<endl;

	return 0;
}
*/
