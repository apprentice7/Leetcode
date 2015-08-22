// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 23-08-2015

/********************************************************************************** 
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
* For example, given n = 3, a solution set is:
* "((()))", "(()())", "(())()", "()(())", "()()()"              
**********************************************************************************/

/* algorithm attributes to 
https://github.com/haoel/leetcode/blob/master/algorithms/generateParentheses/generateParentheses.cpp
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        string out;
        if(n <= 0) return output;
        if(n == 1){
        	out = "()";
        	output.push_back(out);
        	return output;
        } 
        else{
        	generate(output, n, n, out);
        }
        return output;
    }
private: 
	void generate(vector<string>& v, int left, int right, string s){
		if(left == 0 && right == 0){
			v.push_back(s);
			return;
		}
		if(left > 0){
			generate(v, left-1, right, s+'(');
		}
		if(right > 0 && right > left){
			generate(v, left, right-1, s+')');
		}

	}
};

/* //For testing
int main(){
	Solution test;
	vector<string> result;
    result = test.generateParenthesis(4);
	for(int t=0; t<result.size();t++){
		cout << result[t] << endl;
	}
	return 0;
}
*/
