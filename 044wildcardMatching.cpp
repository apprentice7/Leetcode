// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 17-09-2015

/********************************************************************************** 
* Implement wildcard pattern matching with support for '?' and '*'.
* '?' Matches any single character.
* '*' Matches any sequence of characters (including the empty sequence).
* The matching should cover the entire input string (not partial).
* The function prototype should be:
* bool isMatch(const char *s, const char *p)
* Some examples:
* isMatch("aa","a") → false
* isMatch("aa","aa") → true
* isMatch("aaa","aa") → false
* isMatch("aa", "*") → true
* isMatch("aa", "a*") → true
* isMatch("ab", "?*") → true
* isMatch("aab", "c*a*b") → false
**********************************************************************************/
/*
idea:
1. a loop to go through string s and string p.
2. if s[i] == p[j] or p[j] == '?' move to next char
3. if p[j] == *, record the position of i and j, continue compare s[i] with p[j+1]
4. once not equal, check if position marker jmark is -1:
	if -1 return false
	if not -1 restore i and j to imark+1 and jmark+1. And let imark+1
5. go through s[i] to jump out.
	if i<n still holds but j<m not return false;
	if i<n not holds j<m holds:
		if p[j] and after are all * return true
		else return false
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        int j = 0;
        int i = 0;
		int imark = -1;
		int jmark = -1;
        while(i<n){
			if(j < m && p[j] =='?' || s[i] == p[j]){
				i++;
				j++;
			}
        	else if(j < m && p[j] == '*'){
				imark = i;
				jmark = j;
				j++;
			}
			//This part form another loop
			//if the there is a * before, try to loop i by s[i]==*
			//every * is a start of p string
			else if(jmark != -1){
				j = jmark +1;
				//imark++;
				i = ++imark;
			}
			else return false;
       	}
		while(j < m && p[j] == '*') j++;
		return j==m;
    }
};

/* //For testing
int main(){
	Solution test;
	string a= "abefcdgiescdfimde";
	string b= "ab*cd?i*de";
	cout << test.isMatch(a,b) << endl;
	return 0;
}
*/
