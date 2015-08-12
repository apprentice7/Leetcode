// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 13-08-2015

/***********************************************************************
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
***********************************************************************/


#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	bool isMatch(string s, string p){
		int i = 0;
		int j = 0;
		for(j=0; j<p.size();j++){
			if(p[j] == s[0] || p[j] == '.'){
				if(Match(i,j,s,p)){
					return true;
				}
			}
		}
		return false;
	}
private:
	bool Match(int i, int j, string s, string p){
		cout << "test: " << i << " " << j << endl;
		if(i >= s.size() && j >= p.size()){
			cout << "1" << endl;
			return true;
		}
		if(i >= s.size()){
			cout << "2" << endl;
			return true;
		}
		if(j >= p.size()){
			cout << "3" << endl;
			return false;
		}
		if(p[j] == s[i]){
			cout << "4" << endl;
			return Match(i+1,j+1,s,p);
		}
		if(p[j] == '.'){
			cout << "5" << endl;
			return Match(i+1,j+1,s,p);
		}
		if(p[j] == '*' && p[j-1] == '.'){
			cout << ".*" << endl;
			return true;
		}
		if(p[j] == '*' && s[i] == s[i-1]){
			cout << "6" << endl;
			return Match(i+1,j,s,p);
		}
		if(p[j] == '*' && s[i] != s[i-1]){
			cout << "7" << endl;
			return Match(i,j+1,s,p);
		}
		else{
			cout << "8" << endl;
			return false;
		}
	}
};
/* //For testing
int main(){
	Solution s;
	string a = "aaaaaaaabbbb";
	string b = "c*a*bbbb";
	bool result = s.isMatch(a,b);
	cout << "result: " << result << endl;
	return 0;
}
*/


