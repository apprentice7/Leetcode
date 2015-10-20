// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 20-10-2015

/********************************************************************************** 
* Given an array with n objects colored red, white or blue, sort them so that objects of 
* the same color are adjacent, with the colors in the order red, white and blue.
* Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
* Note:
* You are not suppose to use the library's sort function for this problem.
* Follow up:
*  > A rather straight forward solution is a two-pass algorithm using counting sort.
*  > First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array 
*    with total number of 0's, then 1's and followed by 2's.
*  > Could you come up with an one-pass algorithm using only constant space?
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
    int n = nums.size();
		if(n<=0) return;
		int i = 0;
		int j = n-1;
		while(i<n){
			int tmp = -1;
			if(nums[i] == 0){
				tmp = i;
				while(tmp>0 && nums[tmp-1] != 0){
					swap(nums[tmp],nums[tmp-1]);
					tmp--;
				}
			}
			i++;
		}
		while(j>=0){
			int tmp = -1;
			if(nums[j] == 2){
				tmp = j;
				while(tmp<n-1 && nums[tmp+1] != 2){
					swap(nums[tmp],nums[tmp+1]);
					tmp++;
				}
			}
			j--;
		}
    }
};

/* //For testing
int main(){
	Solution test;
	int arr[] = {1,2,1,0,1,0,2,0,1,0,2};
	vector<int> v;
	v.assign(arr,arr+11);
	test.sortColors(v);
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}
*/
