// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Tony
// Date   : 06-10-1015

/********************************************************************************** 
* Follow up for "Unique Paths":
* Now consider if some obstacles are added to the grids. How many unique paths would there be?
* An obstacle and empty space is marked as 1 and 0 respectively in the grid.
* For example,
* There is one obstacle in the middle of a 3x3 grid as illustrated below.
* [
*   [0,0,0],
*   [0,1,0],
*   [0,0,0]
* ]
* The total number of unique paths is 2.
* Note: m and n will be at most 100.
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    int m = obstacleGrid.size();
		if(m<=0) return 0;
		int n = obstacleGrid[0].size();
		if(obstacleGrid[0][0] == 1) return 0;
		for(int i=0; i<m; i++){
			if(obstacleGrid[i][0] == 1){
				while(i<m){
					obstacleGrid[i][0] = 0;
					i++;
				}
			}
			else{
				obstacleGrid[i][0] = 1;
			}
		}
		for(int j=1; j<n; j++){
			if(obstacleGrid[0][j] == 1){
				while(j<n){
					obstacleGrid[0][j] = 0;
					j++;
				}
			}
			else{
				obstacleGrid[0][j] = 1;
			}
		}

		for(int i=1; i<m; i++){
			for(int j=1; j<n; j++){
				if(obstacleGrid[i][j] == 1) {
					obstacleGrid[i][j] = 0;
				}
				else{
					int temp = obstacleGrid[i][j-1] + obstacleGrid[i-1][j];
					obstacleGrid[i][j] = temp;
				}
			}
		}
		return obstacleGrid[m-1][n-1];
    }
};

/* //For testing
int main(){
	Solution test;
	vector<int> t;
	vector<vector<int> >input;
	int arr[] = {0,0};
	int arr2[] = {1,1};
	t.assign(arr,arr+2);
	input.push_back(t);
	t.clear();
	t.assign(arr2,arr2+2);
	input.push_back(t);
	t.clear();
	t.assign(arr,arr+2);
	t.push_back(0);
	input.push_back(t);
	
	cout << test.uniquePathsWithObstacles(input)<< endl;
	return 0;
}
*/
