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
			else if(jmark != -1){
				j = jmark +1;
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
