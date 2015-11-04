// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 03-11-2015

/**********************************************************************************
* Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
* Below is one possible representation of s1 = "great":
*     great
*    /    \
*   gr    eat
*  / \    /  \
* g   r  e   at
*            / \
*           a   t
* To scramble the string, we may choose any non-leaf node and swap its two children.
* For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
*     rgeat
*    /    \
*   rg    eat
*  / \    /  \
* r   g  e   at
*            / \
*           a   t
* We say that "rgeat" is a scrambled string of "great".
* Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
*     rgtae
*    /    \
*   rg    tae
*  / \    /  \
* r   g  ta  e
*        / \
*       t   a
* We say that "rgtae" is a scrambled string of "great".
* Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
**********************************************************************************/

/* idea adopted from: https://leetcode.com/discuss/36470/share-my-4ms-c-recursive-solution 
Main idea: check substring in s1 and s2 that are character matched.
Use <char, int> map -> map[s1[i]] will match map[s2[i]] and give a sum of 0.
To check scramble is to check the substring for s1 and s2 recursively.
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
		const int n = s1.size();
		if(s1==s2) return true;
		unordered_map<char,int> strMap;
		
		for(int i=0; i<n; i++){
			strMap[s1[i]]++;
			strMap[s2[i]]--;
		}
		for(int i=0; i<n; i++){
			if(strMap[s1[i]] != 0) return false;
		}
		for(int i=1; i<n; i++){
			if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))
				return true;
			if(isScramble(s1.substr(0,i),s2.substr(n-i)) && isScramble(s1.substr(i),s2.substr(0,n-i)))
				return true;
		}
		return false;
    }
};

/* //For testing
int main(){
	Solution test;
	string s1 = "great";
	string s2 = "rgtae";

	cout << test.isScramble(s1,s2) << endl; 

	return 0;
}
*/
