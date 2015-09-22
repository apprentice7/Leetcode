// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 22-09-2015

/********************************************************************************** 
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* Each element in the array represents your maximum jump length at that position. 
* Your goal is to reach the last index in the minimum number of jumps.
* For example:
* Given array A = [2,3,1,1,4]
* The minimum number of jumps to reach the last index is 2. 
* (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int> > result;
		if(n<1) return result;
		else if(n==1) {
			result.push_back(nums);
			return result;
		}
		else{
			vector<int> temp;
			vector<int> pnums = nums;
			result = pushToVector(pnums, temp, result);
			return result;
		}
	}

	vector<vector<int> > pushToVector(vector<int> remainNum, vector<int> temp, vector<vector<int> > output){
		int nsize = remainNum.size();
		if(nsize==1) {
			bool flag = false;
			temp.push_back(remainNum[0]);
			for(int i=0; i<output.size(); i++){
				if(output[i] == temp) {
					flag = true;
					break;
				}
			}
			if(flag == false){
				output.push_back(temp);
				return output;
			}
			else{
				return output;
			}
		}
		else {
			for(int k=0; k<nsize; k++){
				int number = remainNum[k];
				temp.push_back(number);
				remainNum.erase(remainNum.begin()+k);
				output = pushToVector(remainNum, temp, output);
				temp.pop_back();
				remainNum.insert(remainNum.begin(), number);
			}
		}
		return output;
	}
};

/* //For testing
int main(){
	Solution test;
	int arr[] = {1,2,3};
	vector<int> v;
	v.assign(arr,arr+3);

	vector<vector<int> > re;
	re = test.permute(v);
	for(int i=0; i<re.size(); i++){
		for(int k=0; k<re[i].size(); k++){
			cout << re[i][k] << " ";
		}
		cout << endl;
	}

	return 0;
}
*/
