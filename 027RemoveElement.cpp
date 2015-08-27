// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 27-08-2015

/********************************************************************************** 
* Given an array and a value, remove all instances of that value in place and return the new length.
* The order of elements can be changed. It doesn't matter what you leave beyond the new length.          
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
		int len = 0;

		for(int i=0;i<size;i++){
			if(nums[i] != val){
				nums[len] = nums[i]; 
				len++;
			}
		}
		return len;
    }
};
/* //For testing
int main(){
	Solution test;
	int arr[] = {0,0,1,1,1,1,2,3,4,5,6};
	vector<int> v;
	v.assign(arr,arr+11);
	cout << test.removeElement(v,1) << endl;

	return 0;
}
*/
