// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 18-08-2015

/********************************************************************************** 
* 
* Given an array S of n integers, find three integers in S such that the sum is 
* closest to a given number, target. Return the sum of the three integers. 
* You may assume that each input would have exactly one solution.
* 
*     For example, given array S = {-1 2 1 -4}, and target = 1.
* 
*     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
* 
*               
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int n = nums.size();
		int Closet = abs(nums[0] + nums[1] + nums[n-1] - target);
		int sum = nums[0] + nums[1] + nums[n-1];

        if(n < 3) return 0;
		else if(n == 3) return nums[0]+nums[1]+nums[2];
		else{
			sort(nums.begin(),nums.end());
			for(int i=0; i<n-2; i++){
				while(i>0 && nums[i] == nums[i-1]) i++;
				int first= nums[i];
				int left = i+1;
				int right = n-1;
				
				while(left < right){
					int second = nums[left];
					int third = nums[right];
					int total = first + second + third;
					int distance = abs(total - target);
					if(distance < Closet){
						Closet = distance;
						sum = total;
					}
					if(total == target){
						return target;
					}
					else if (total > target){
						while(right>0 && nums[right] == nums[right-1]) right--;
						right--;
					}
					else{
						while(left<n && nums[left] == nums[left+1]) left++;
						left++;
					}
				}
			}
		}
		return sum;
    }
};
/* //For testing
int main(){
	//int a[] = {-1, 0, -2, -3, 1, 0, 3, -5, 8, 2, 10, 0};
	//int a[] = {-1, 0, 1, 2, -1, 1, -4};
	//int a[] = {-1, 1, 1, 1, -1, -1, 0,0,0};
	int a[] = {1,1,1,1};
	std::vector<int> v;
	v.assign(a,a+4);
	Solution s;
    cout << s.threeSumClosest(v, 4) << endl;
	
	return 0;
}
*/
