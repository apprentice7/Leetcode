// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 11-09-2015



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector<int> > output;
		sort(candidates.begin(),candidates.end());
		if(candidates[0] > target) return output;

		vector<int> temp;
		findCombination(output, temp, candidates, target);
    }

	void findCombination(vector< vector<int> >& output, vector<int> temp, vector<int>& candidates, int target){
		for(int i=0; i<candidates.size(); i++){
			if(candidates[i] < target){
				target = target - candidates[i];
				temp.push_back(candidates[i]);
				findCombination(output, temp, candidates, target);
			}
			else if(candidates[i] > target){
				break;
			}
			else if(candidates[i] == target){
				temp.push_back(candidates[i]);
				output.push_back(temp);
				return;
			}
		}
		return;
	}
};
 //For testing
int main(){
	Solution test;
	

	return 0;
}
