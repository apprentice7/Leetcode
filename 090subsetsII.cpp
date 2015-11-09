// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 09-11-2015

/********************************************************************************** 
* Given a collection of integers that might contain duplicates, S, return all possible subsets.
* Note:
* Elements in a subset must be in non-descending order.
* The solution set must not contain duplicate subsets.
* For example,
* If S = [1,2,2], a solution is:
* [
*   [2],
*   [1],
*   [1,2,2],
*   [2,2],
*   [1,2],
*   []
* ]
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int> > subsetsWithDup(vector<int>& nums) {
		vector<vector<int> > output;
		vector<int> temp;
		sort(nums.begin(),nums.end());
		
		getSubset(output, temp, nums, 0);
		
		return output;
  }
private:
	void getSubset(vector<vector<int> > &output,vector<int> &temp,vector<int> &nums,int start){
		output.push_back(temp);
		for(int i=start; i<nums.size(); i++){
			if(i == start || nums[i] != nums[i-1]){
				temp.push_back(nums[i]);
				getSubset(output,temp,nums,i+1);
				temp.pop_back();
			}
		}
	}
};

/* //For testing
int main(){
	Solution test;	
	int a[] =  {1,2,2};
	vector<int> re;
	re.assign(a,a+3);
	vector<vector<int> >out;
	out = test.subsetsWithDup(re);
	for(int i=0; i<out.size(); i++){
		for(int j=0; j<out[i].size(); j++){
			cout << out[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
*/
