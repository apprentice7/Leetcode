// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 28-10-2015

/********************************************************************************** 
* Follow up for "Remove Duplicates":
* What if duplicates are allowed at most twice?
* For example,
* Given sorted array A = [1,1,1,2,2,3],
* Your function should return length = 5, and A is now [1,1,2,2,3].
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if(n<2) return n;
		bool flag = false;
		int count = 1;
		int i = 1;
		
		while(i<nums.size()){
			if(nums[i] == nums[i-1] && flag == true){
				//delete
				nums.erase(nums.begin()+i,nums.begin()+i+1);
			}
			else if(nums[i] == nums[i-1] && flag == false){
				flag = true;
				count++;
				i++;
			}
			else{
				flag = false;
				count++;
				i++;
			}
		}
		return count;
    }
};

/* //For testing
int main(){
	Solution test;
	int a[] = {1,1,1,1,1,2,2,2,3,4,5,5,5};
	vector<int> v;
	v.assign(a,a+13);
	cout<<test.removeDuplicates(v)<<endl;
	for(int i=0; i<v.size();i++){
		cout<<v[i] << " ";
	}
	cout << endl;
	return 0;
}
*/
