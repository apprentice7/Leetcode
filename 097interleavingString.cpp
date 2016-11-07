// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 24-08-2016

/********************************************************************************** 
* 
* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
* 
* For example,
* Given:
* s1 = "aabcc",
* s2 = "dbbca",
* 
* When s3 = "aadbbcbcac", return true.
* When s3 = "aadbbbaccc", return false.
* 
*               
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.size() + s2.size()) != s3.size()) return false;

        bool table[s1.size()+1][s2.size()+1];

        for(int i=0; i<s1.size()+1; i++){
            for(int j=0; j<s2.size()+1; j++){
                if(i == 0 && j == 0) table[i][j] = true;
                else if(i == 0) table[i][j] = (table[i][j-1]) && (s2[j-1] == s3[i+j-1]);
                else if(j == 0) table[i][j] = (table[i-1][j]) && (s1[i-1] == s3[i+j-1]);
                else table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1]) || (table[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }

        return table[s1.size()][s2.size()];
    }
};

/* unit testing */
int main() {
	Solution test;
	
	string s11 = "aabcc";
	string s22 = "dbbca";
	string s33 = "aadbbcbcac";
	string s34 = "aadbbbaccc";
	cout << test.isInterleave(s11, s22, s33) << endl;
    cout << test.isInterleave(s11, s22, s34) << endl;
	return 0;
}