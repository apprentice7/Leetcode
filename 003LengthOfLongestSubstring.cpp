// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Tony
// Date   : 28-07-1015

/********************************************************************************** 
* 
* Given a string, find the length of the longest substring without repeating characters. 
* For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
* which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*               
**********************************************************************************/

/********************************************************************************** 
*
* Algorithm:
*	A hash table stores character and its postion.
*	Go through the string. Using LastChar to label the first postion that the 
*	character appeared sescond time. The difference between current positon
*	and LastChar is the length of substring.
*	Iteratively scan all string will give the longest substring in linear time.
**********************************************************************************/

#include <iostream>
#include <string>
#include <string.h>
#include <map>
using namespace std;

class Solution{
public:
	int lengthOfLongestSubstring(string s){
		map<char,int> hashtable;
		int longest=0;
		int LastChar = -1;
		//Go through every character linearly
		for(int position = 0;position<s.length();position++){
			//Find the most recent repeated character in hash table than move the LastChar forward
			if(hashtable.find(s[position]) != hashtable.end() && LastChar < hashtable[s[position]]){
				LastChar = hashtable[s[position]];
			}
			if(position-LastChar > longest){
				longest = position - LastChar;
			}
			hashtable[s[position]] = position;
		}
		return longest;
	}
};

/* 
//for testing
int main (){
	string s = "abcabcbb";
	Solution solution;
    cout << s << " : " << solution.lengthOfLongestSubstring(s) << endl;
    s = "bbbbb";
    cout << s << " : " << solution.lengthOfLongestSubstring(s) << endl;
    s = "aabbcdefghefghbcdbcda";
    cout << s << " : " << solution.lengthOfLongestSubstring(s) << endl;

	return 0;
}
*/

