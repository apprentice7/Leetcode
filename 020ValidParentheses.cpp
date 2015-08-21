// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 19-08-2015

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 == 1 || s.size() < 0) return false;
		string stack;
		while(s.size()>0){
			char Last = s.back();
			if(Last == '}' || Last == ']' || Last == ')'){
				//if (s.size()<=0) return false;
				s.pop_back();
				stack.push_back(Last);
			}
			else if(Last == '{' || Last == '[' || Last == '('){
				char StackLast = stack.back();
				if(stack.back() ==NULL) return false;
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
	cout << test.isValid(s) << endl;
	
	return 0;
}
