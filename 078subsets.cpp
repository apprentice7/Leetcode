// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 27-10-2015

/********************************************************************************** 
* Given a set of distinct integers, S, return all possible subsets.
* Note:
* Elements in a subset must be in non-descending order.
* The solution set must not contain duplicate subsets.
* For example,
* If S = [1,2,3], a solution is:
* [
*   [3],
*   [1],
*   [2],
*   [1,2,3],
*   [1,3],
*   [2,3],
*   [1,2],
*   []
* ]
**********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int> >output;
		vector<int> temp;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		
		output.push_back(temp);
		for(int i=1; i<=n; i++){
			getComb(output,temp,nums,1,n,i);
		}
		return output;
    }
private:
	void getComb(vector<vector<int> >&output, vector<int> &temp,vector<int> &nums, int a, int n,int k){
		if(k == 0) {
			output.push_back(temp);
			return;
		}
		else{
			for(int i=a; n-i+1>=k; i++){
				temp.push_back(nums[i-1]);
				getComb(output,temp,nums,i+1,n,k-1);
				temp.pop_back();
			}
		}
	}
};

/* //For testing
int main(){
	Solution test;
	vector<vector<int> > re;
	int arr[] = {1,2,3,5};
	vector<int> v;
	v.assign(arr,arr+4);
	re = test.subsets(v);

	for(int i=0; i<(int)re.size();i++){
		for(int j=0; j<(int)re[i].size();j++){
			cout << re[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
*/
