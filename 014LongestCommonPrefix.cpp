// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 17-08-2015

/********************************************************************************** 
* 
* Write a function to find the longest common prefix string amongst an array of strings.
* 
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	string longestCommonPrefix(vector<string>& strs){
		string out;
		for(int i=0; i<strs[0].size();i++){
			int j =0;
			while(j<strs.size() && strs[0][i] == strs[j][i]){
				j++;
			}
			if (j != strs.size()){
				for(int x=0; x<i; x++){
					out = out + strs[0][x];
				}
				return out;
			}
		}
		return strs[0];
	}
};

/* //For testing
int main(){
	const char* s[]={"abcd","abc","a","abcd"};
    vector<string> v(s, s+4);
	Solution re;
    cout << re.longestCommonPrefix(v) <<endl;
	return 0;
}
*/
