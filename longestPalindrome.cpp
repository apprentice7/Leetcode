// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 05-08-1015

/********************************************************************************** 
* 
* Given a string S, find the longest palindromic substring in S. 
* You may assume that the maximum length of S is 1000, 
* and there exists one unique longest palindromic substring.
*               
**********************************************************************************/


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		string longest;
		string temp;
		for (int i=0;i<s.size();i++){
			temp = FindPalindrome(s,i,i);
			if(longest.size() < temp.size()){
				longest = temp;
			}
			temp = FindPalindrome(s,i,i+1);
			if(longest.size() < temp.size()){
				longest = temp;
			}
		}
		return longest;
	}
private:
	string FindPalindrome(string s, int i, int j){
		int n = s.size();
		int Left = i;
		int Right = j;
		while(Left>=0 && Right<=n-1 && s[Left] == s[Right]){
			Left = Left - 1;
			Right = Right + 1;
		}
		return s.substr(Left+1,Right-Left-1);
	}
};

/* //For testing
int main() {
	string s = "abcdefedcbaa";
	Solution solution;
	string output;
	output = solution.longestPalindrome(s);

	cout << s << " : " << output << endl;
	return 0;
}
*/
