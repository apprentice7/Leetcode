// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 19-10-2015

/********************************************************************************** 
* Write an efficient algorithm that searches for a value in an m x n matrix. 
* This matrix has the following properties:
* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.
* For example,
* Consider the following matrix:
* [
*   [1,   3,  5,  7],
*   [10, 11, 16, 20],
*   [23, 30, 34, 50]
* ]
* Given target = 3, return true.
**********************************************************************************/.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
		if(n<=0) return false;
		int m = matrix[0].size();
		if(m<=0) return false;
		int cLow = 0, rLow = 0;
		int cHigh = n-1, rHigh = m-1;
		int row = -1;

		while(cLow < cHigh){
			int cMiddle = (cHigh + cLow) / 2;
			if(target > matrix[cMiddle][0]){
				cLow = cMiddle+1;
			}
			else if(target < matrix[cMiddle][0]){
				cHigh = cMiddle-1;
			}
			else return true;
		}
		if(target < matrix[cLow][0]) row = cLow - 1;
		else if(target > matrix[cLow][0]) row = cLow;
		else return true;
		if(row<0) return false;

		while(rLow < rHigh){
			int rMiddle = (rHigh + rLow) / 2;
			if(target > matrix[row][rMiddle]){
				rLow = rMiddle+1;
			}
			else if(target < matrix[row][rMiddle]){
				rHigh = rMiddle-1;
			}
			else return true;
		}
		if(matrix[row][rLow] == target) return true;
		else return false;
    }
};

/* //For testing
int main(){
	Solution test;
	vector<vector<int> > m;
	vector<int> temp;
	int arr1[] = {1,3,5,7};
	int arr2[] = {10,11,16,20};
	int arr3[] = {23,30,34,50};
	temp.assign(arr1,arr1+4);
	m.push_back(temp);
	temp.clear();
	temp.assign(arr2,arr2+4);
	m.push_back(temp);
	temp.clear();
	temp.assign(arr3,arr3+4);
	m.push_back(temp);
	cout << test.searchMatrix(m, 0) << endl;
	
	return 0;
}
*/
