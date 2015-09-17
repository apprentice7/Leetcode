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

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        int j = 0;
        int i = 0;
        if(n == 0 && n==m) return true;
        if(n == 0 || m==0) return false;
        if(m > n) return false;
        //for(int i=0; i<n; i++){
        while(i<n){
        	cout << "s[i]: " << s[i] << endl;
        	cout << "p[j]: " << p[j] << endl;
        	cout << endl;
        	if(j>=m) return false;
        	if(s[i] == p[j] || p[j] == '?') {
        		j++;
        		i++;
        	}
        	else if(p[j] == '*'){
        		if(j==m-1) return true;
        		else if(j==m-2){
        			if(p[j+1]==s[i] && i==n-1) return true;
        			else if(p[j+1]==s[i] && i!=n-1) return false;
        			else{
        				i++;
        			}
        		} 
        		else if(j<m-2){
        			if(p[j+1] == s[i]){
        				i++;
        				j=j+2;
        			}
        			else{
        				i++;
        			}
        		}	
        	}
        	else{
        		cout << "error match" << endl;
        		return false;
        	}
       	}
       	cout << "i: " << i << endl;
       	cout << "j: " << j << endl;
       	if(j==m-1 && p[j]=='*') return true;
       	if(j < m) return false;
       	else return true;
    }
};

int main(){
	Solution test;
	string a= "abefcdgiescdfimde";
	string b= "ab*cd?i*de";
	cout << test.isMatch(a,b) << endl;
	return 0;
}

