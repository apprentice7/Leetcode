// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 12-09-2015

/********************************************************************************** 
* Given a collection of candidate numbers (C) and a target number (T), find all 
* unique combinations in C where the candidate numbers sums to T.
* Each number in C may only be used once in the combination.
* Note:
* > All numbers (including target) will be positive integers.
* > Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
*   (ie, a1 ≤ a2 ≤ … ≤ ak).
* > The solution set must not contain duplicate combinations.
* For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
* A solution set is: 
* [1, 7] 
* [1, 2, 5] 
* [2, 6] 
* [1, 1, 6]     
**********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector <vector<int> > output;
		sort(candidates.begin(),candidates.end());
		if(candidates[0] > target || candidates.size() < 1) return output;

		vector<int> temp;
		findCombination(output, temp, candidates, target, 0);
		return output;
    }

	void findCombination(vector< vector<int> >& output, vector<int>& temp, vector<int>& candidates, int target, int pos){
		if(target < 0){
			return;
		}
		if(target == 0){
			output.push_back(temp);
			return;
		}
		for(int i=pos; i<candidates.size(); i++){
			if(i>pos && candidates[i] == candidates[i-1]) continue;
			temp.push_back(candidates[i]);
			findCombination(output,temp,candidates,target - candidates[i],i+1);
			temp.pop_back();
		}
	}
};
/* //For testing
int main(){
	Solution test;
	vector<int> candidates;
	int arr[] = {2,3,6,7};
	candidates.assign(arr,arr+4);
	vector< vector<int> > result;
	result = test.combinationSum(candidates, 7);
	for(int i=0; i< result.size();i++){
		for(int j=0; j< result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
*/
