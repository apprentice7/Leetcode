// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 01-10-2015

/********************************************************************************** 
* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
* return the length of last word in the string.
* If the last word does not exist, return 0.
* Note: A word is defined as a character sequence consists of non-space characters only.
* For example, 
* Given s = "Hello World",
* return 5.
**********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int temp = 0;
        int last = 0;
        for(int i=0; i<n; i++){
        	if(s[i] == ' '){
        		if(temp !=0 ) last = temp;
        		temp = 0;
        	}
        	else{
        		temp++;
        	}
        }
        if(temp == 0) return last;
        return temp;
    }
};

/* //For testing
int main(){
	Solution test;
	string s = "hello world a    ";

	cout<< test.lengthOfLastWord(s)<<endl;

	return 0;
}
