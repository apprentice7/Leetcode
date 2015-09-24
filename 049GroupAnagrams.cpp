// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 23-09-2015

/********************************************************************************** 
* Given an array of strings, group anagrams together.
* For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
* Return:
* [
*   ["ate", "eat","tea"],
*   ["nat","tan"],
*   ["bat"]
* ]
* Note:
* For the return value, each inner list's elements must follow the lexicographic order.
* All inputs will be in lower-case.
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

/* idea:
	1: sort the strs before find
	2: add sorted strs into map for compare and push back
*/

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        int n = strs.size();
		vector<vector<string> > output;
		if(n<1) return output;
		map<string, int> dict;

		for(int i=0; i<n; i++){
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			
			if(dict.find(temp) == dict.end()){
				dict[temp] = output.size();
				vector<string> toAdd;
				toAdd.push_back(strs[i]);
				output.push_back(toAdd);
			}
			else{
				output[dict[temp]].push_back(strs[i]);
			}	
		}
		for(int k=0; k<output.size(); k++){
				sort(output[k].begin(), output[k].end());
		}
		return output;

    }
};

/* //For testing
int main(){
	Solution test;
	string arr[]={"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<string> v;
	v.assign(arr,arr+6);
	vector<vector<string> > re;
	re = test.groupAnagrams(v);

	for(int i=0; i<re.size(); i++){
		for(int j=0; j<re[i].size(); j++){
			cout<< re[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
*/
