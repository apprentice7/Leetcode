// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 21-08-2015

/********************************************************************************** 
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
* determine if the input string is valid.
* The brackets must close in the correct order, "()" and "()[]{}" are all valid 
* but "(]" and "([)]" are not.
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 == 1 ) return false;
		string stack;
		while(s.size()>0){
			char Last = s.back();
			if(Last == '}' || Last == ']' || Last == ')'){
				s.pop_back();
				stack.push_back(Last);
			}
			else if(Last == '{' || Last == '[' || Last == '('){
				if(stack.empty()) return false;
				char StackLast = stack.back();
				if((Last == '{' && StackLast=='}') || (Last == '[' && StackLast==']') || (Last == '(' && StackLast==')')){
					s.pop_back();
					stack.pop_back();
				}
				else{
					return false;
				}	
			}
			else{
				s.pop_back();
			}
		}
		return(s.size() == 0 && stack.size() == 0);
    }
};

int main(){
	Solution test;
	string s = "}}(]}}){)(])](}{{}[]";
	//string s = "}}[]";
	cout << test.isValid(s) << endl;
	
	return 0;
}
