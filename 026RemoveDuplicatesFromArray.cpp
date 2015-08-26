// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 26-08-2015

/********************************************************************************** 
* Given a sorted array, remove the duplicates in place such that each element appear 
* only once and return the new length.
* Do not allocate extra space for another array, you must do this in place with constant memory.
* For example,
* Given input array A = [1,1,2],
* Your function should return length = 2, and A is now [1,2].
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return size;

        int len = 1;
        for(int i=0; i< size-1; i++){
        	if(nums[i] != nums[i+1]){
        		nums[len] = nums[i+1];
        		len++;
        	}
        }
        return len;
    }
};

/* //For testing
int main(){
	Solution test;
	int arr[]={1,1,1,1,4,5,6,7};
	vector<int> v;
	v.assign(arr,arr+8);
	cout << test.removeDuplicates(v) << endl;

	return 0;
}
*/
