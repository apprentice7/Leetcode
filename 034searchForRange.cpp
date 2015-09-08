// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 09-09-2015

/********************************************************************************** 
* Given a sorted array of integers, find the starting and ending position of a given target value.
* Your algorithm's runtime complexity must be in the order of O(log n).
* If the target is not found in the array, return [-1, -1].
* For example,
* Given [5, 7, 7, 8, 8, 10] and target value 8,
* return [3, 4].              
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	vector<int> searchRange(vector<int>& nums, int target){
		vector<int> output;
		int n = nums.size();
		int Lower = 0;
		int Upper = n;
		int i = (Upper + Lower)/2;
		int starting = -1;
		int ending = -1;

		while(target != nums[i] && Upper > Lower){
			if(target < nums[i]){
				 Upper = i;
				 i = (Upper + Lower)/2;
				 if(i == Upper) break;
			}
			else{
				Lower = i;
				i = (Upper + Lower)/2;
				if(i == Lower) break;
			}
		}
		cout << nums[i] << endl;
		cout << i << endl;
		if(target!=nums[i]) {
			output.push_back(starting);
			output.push_back(ending);
		}
		else{
			int starting = i;
			int ending = i;
			while(nums[starting-1] == nums[starting] && starting>0){
				starting--;
			}
			while(nums[ending+1] == nums[ending] && ending<n-1){
				ending++;
			}
			output.push_back(starting);
			output.push_back(ending);
		}
		return output;
	}
};

/* //For testing
int main(){
	Solution test;
	int arr[] = {0,0,0,0,2,2,3,3,4,4,5,5,5,6,7,7,8,9,9,9,10};
	vector<int> v;
	v.assign(arr,arr+21);
	vector<int> result;
	result = test.searchRange(v, 10);

	cout << result[0] << result[1] << endl;
	return 0;
}
*/
