// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 21-09-2015

/********************************************************************************** 
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* Each element in the array represents your maximum jump length at that position. 
* Your goal is to reach the last index in the minimum number of jumps.
* For example:
* Given array A = [2,3,1,1,4]
* The minimum number of jumps to reach the last index is 2. 
* (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
**********************************************************************************/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution{
public:
	int jump(vector<int>& nums){
		int n = nums.size();
		int ret = 0;
		int last = 0;
		int curr = 0;

		for(int i=0; i<n; i++){
			if(i>last){
				if(last == curr && last < n-1) return -1;
				last = curr;
				++ret;
			}
			curr = max(curr,i+nums[i]);
		}
		return ret;
	}
};

/* // cannot pass time limit
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
		int output = 0;
		if(n<1) return 0;

		found(nums, n-1, output);
		return output;
    }
	void found(vector<int>& nums, int pos, int& count){
		int nPos = -1;
		int i = pos-1;
		int temp = -1;
		for(; i>0; i--){
			if(nums[i] >= (pos-i)){
				nPos = i;
				temp = nums[i];
			}
			while(nums[i] <= temp && i>0){
				i--;
			}
		}
		if(nPos > 0) {
			count++;
			found(nums, nPos, count);
		}
		else{
			count++;
			return;
		}
	}
};
*/
/* //For testing
int main(){
	Solution test;
	int arr[] = {2,3,1,1,0,4};
	vector<int> v;
	v.assign(arr,arr+6);
	cout << test.jump(v) << endl;

	return 0;
}
*/
