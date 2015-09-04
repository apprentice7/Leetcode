// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 04-09-2015

/********************************************************************************** 
* Implement next permutation, which rearranges numbers into the lexicographically next 
* greater permutation of numbers.
* If such arrangement is not possible, it must rearrange it as the lowest possible order 
* (ie, sorted in ascending order).
* The replacement must be in-place, do not allocate extra memory.
* Here are some examples. Inputs are in the left-hand column and its corresponding outputs 
* are in the right-hand column.
*   1,2,3 → 1,3,2
*   3,2,1 → 1,2,3
*   1,1,5 → 1,5,1          
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
		if(size<=1) return;

		for(int i=size-1; i>0; i--){
			if(nums[i-1] < nums[i]){
				int j = size-1;
				while(nums[i-1] >= nums[j]){
					j--;
				}
				int temp = nums[j];
				nums[j] =nums[i-1];
				nums[i-1] = temp;
				reverse(nums.begin()+i, nums.end());
				return;
			}
			if(i == 1){
				reverse(nums.begin(),nums.end());
				return;
			}
		}
    }
};

/* //For testing
int main(){
	Solution test;
	int arr[] = {1,2,3,4};
	vector<int> v;
	v.assign(arr,arr+4);
	test.nextPermutation(v);
	for(int i=0; i<v.size(); i++){
		cout << v[i] << endl;
	}
	return 0;
}
*/
