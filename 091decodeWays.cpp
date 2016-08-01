// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 10-11-2015

/********************************************************************************** 
* A message containing letters from A-Z is being encoded to numbers using the following mapping:
* 'A' -> 1
* 'B' -> 2
* ...
* 'Z' -> 26
* Given an encoded message containing digits, determine the total number of ways to decode it.
* For example,
* Given encoded message "12",
* it could be decoded as "AB" (1 2) or "L" (12).
* The number of ways decoding "12" is 2.
**********************************************************************************/

/* Dynamic programming, be careful about '0'. Definination not clear*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
	int n=s.size();
	if(n==0 || s.front() == '0') return 0;
	int first = 1;
	int second = 1;

	for(int i=1; i<n; i++){
		if(s[i] == '0') first = 0;

		if(s[i-1] == '1' || (s[i-1] == '2' && s[i]-'0' <= 6)){
			first = first + second;
			second = first - second;
		}
		else{
			second = first;
		}
	}
	return first;
    }
};

/* //For testing
int main(){
	Solution test;	
	string s = "123102414";
	cout << test.numDecodings(s) << endl;

	return 0;
}
*/
