// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 19-10-2015

/********************************************************************************** 
* Given two words word1 and word2, find the minimum number of steps required to 
* convert word1 to word2. (each operation is counted as 1 step.)
* You have the following 3 operations permitted on a word:
* a) Insert a character
* b) Delete a character
* c) Replace a character
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

/* a typical dynamic programming problem*/
/* idea: https://leetcode.com/discuss/43398/20ms-detailed-explained-c-solutions-o-n-space
using dp[i][j] to represent operations that convert word1[0..i - 1] to word2[0..j - 1]
obviously: dp[i][0] = i && dp[0][j] = j
dp[i][j] ->
  1. words[i] == words[j]  -> dp[i-1][j-1] == dp[i][j]
  2. words[i] != words[j]  -> 2.1 replace words[1] with words[j] -> dp[i-1][j-1]+1 == dp[i][j]
                              2.2 delete/insert words[i] -> dp[i][j] == dp[i-1][j]+1 || dp[i][j-1]+1
  choose the minimal operations between 2.1 and 2.2.
  
construct the dynamic programming model
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(); 
		int n = word2.size();
		vector<vector<int> > dp(m+1, vector<int> (n+1,0));
		for(int i=1; i<=m; i++){
			dp[i][0] = i;
		}
		for(int i=1; i<=n; i++){
			dp[0][i] = i;
		}
		for(int i=1; i<=m; i++){
			for(int j=1; j<=n; j++){
				if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
				else {
					dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i][j-1]+1, dp[i-1][j]+1));
				}
			}
		}
		return dp[m][n];
    }
};

/* //For testing
int main(){
	Solution test;
	string a1 = "words";
	string a2 = "word";
	cout<< test.minDistance(a1,a2) <<endl;

	return 0;
}
*/
