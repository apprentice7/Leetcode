// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 19-10-2015

/********************************************************************************** 
* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
* click to show follow up.
* Follow up:
* Did you use extra space?
* A straight forward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

/* idea: -> O(1) space
1. mark the row and column to be 0
	use matrix[i][0] and matrix[0][j] to mark
	use variable 'colunmn' to mark the column[0]
2. substitute element with 0
	loop should from back to front
	otherwise there will be more 0 than expected
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
		if(n<=0) return;
		int m = matrix[0].size();
		if(m<=0) return;
		int column = -1;

		for(int i=0; i<n; i++){
			if(matrix[i][0] == 0) column = 0;
			for(int j=1; j<m; j++){
				if(matrix[i][j] == 0){
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for(int i=n-1; i>=0; i--){
			for(int j=m-1; j>=1; j--){
				if(matrix[i][0] == 0 || matrix[0][j] == 0){
					matrix[i][j] = 0;
				}
				
			}
			if(column == 0) matrix[i][0] = 0;
		}
		return;
    }
};

/* //For testing
int main(){
	Solution test;
	vector<vector<int> > m;
	vector<int> tmp;
	int arr[] = {1,2,3};
	tmp.assign(arr,arr+3);
	m.push_back(tmp);
	m.push_back(tmp);
	m.push_back(tmp);
	m.push_back(tmp);
	m[2][1] = 0;
	test.setZeroes(m);
	for(int i=0; i<m.size();i++){
		for(int j=0; j<m[0].size();j++){
			cout << m[i][j] << " ";
		}
		cout<< endl;
	}
	return 0;
}
*/
