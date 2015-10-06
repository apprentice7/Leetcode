// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Tony
// Date   : 06-10-1015

/********************************************************************************** 
* Given a m x n grid filled with non-negative numbers, find a path from top left to 
* bottom right which minimizes the sum of all numbers along its path.
* Note: You can only move either down or right at any point in time.
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if(m<=0) return 0;
		int n = grid[0].size();

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(i==0){
					if(j==0) continue;
					else{
						grid[i][j] = grid[i][j-1] + grid[i][j];
					}
				}
				else if(j==0){
					grid[i][j] = grid[i-1][j] + grid[i][j];
				}
				else{
					grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
				}
			}
			
		}
		return grid[m-1][n-1];
    }
};

/* //For testing
int main(){
	Solution test;
	vector<int> t;
	vector<vector<int> >input;
	int arr[] = {0,1,2};
	int arr2[] = {1,2,3};
	t.assign(arr,arr+3);
	input.push_back(t);
	t.clear();
	t.assign(arr2,arr2+3);
	input.push_back(t);
	t.clear();
	t.assign(arr,arr+3);
	t.push_back(0);
	input.push_back(t);
	
	cout << test.minPathSum(input)<< endl;
	return 0;
}
*/
