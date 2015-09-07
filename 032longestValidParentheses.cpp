// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 07-09-2015

/********************************************************************************** 
* Given a string containing just the characters '(' and ')', 
* find the length of the longest valid (well-formed) parentheses substring.
* For "(()", the longest valid parentheses substring is "()", which has length = 2.
* Another example is ")()())", where the longest valid parentheses substring is "()()", 
* which has length = 4.
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int Len = s.size();
		if(Len <= 1) return 0;
		int MaxLen =0;
		int Last = -1;
		vector<int> bracket;

		for(int i=0; i<Len; i++){
			if(s[i] == '('){
				bracket.push_back(i);
			}
			else if(s[i] == ')'){
				if(bracket.size() > 0){
					bracket.pop_back();
					int tmp;
					if(bracket.size() == 0) tmp = i - Last;
					else tmp = i - bracket.back();
					if(MaxLen < tmp) MaxLen = tmp;
				}
				else{
					Last = i;
				}
			}
		}
		return MaxLen;
    }
};

/* //For testing
int main(){
	Solution test;
	string s = ")()())";
	cout << test.longestValidParentheses(s) << endl;

	return 0;
}
*/
