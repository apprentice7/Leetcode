// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 06-10-2015

/********************************************************************************** 
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach 
 * the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *    start                                                  
 *    +---------+----+----+----+----+----+                   
 *    |----|    |    |    |    |    |    |                   
 *    |----|    |    |    |    |    |    |                   
 *    +----------------------------------+                   
 *    |    |    |    |    |    |    |    |                   
 *    |    |    |    |    |    |    |    |                   
 *    +----------------------------------+                   
 *    |    |    |    |    |    |    |----|                   
 *    |    |    |    |    |    |    |----|                   
 *    +----+----+----+----+----+---------+                   
 *                                   finish                  
 * How many possible unique paths are there?
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 * Note: m and n will be at most 100.
 **********************************************************************************/
 
 #include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> v;
		vector<vector<int> > board;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(i==0 || j==0) v.push_back(1);
				else{
					int temp = v[j-1] + board[i-1][j];
					v.push_back(temp);
				}
			}
			board.push_back(v);
			v.clear();
		}
		return board[m-1][n-1];
    }
};

/* //For testing
int main(){
	Solution test;
	cout << test.uniquePaths(3,7) <<endl;
	return 0;
}
*/
