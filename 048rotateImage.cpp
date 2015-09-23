// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 23-09-2015

/********************************************************************************** 
* You are given an n x n 2D matrix representing an image.
* Rotate the image by 90 degrees (clockwise).
* Follow up:
* Could you do this in-place?
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
		int m = n-1;
		int b = (n+1)/2;
		for(int i=0; i<b; i++){
			for(int j=0; j<n/2; j++){
				int temp = matrix[i][j];
				matrix[i][j] = matrix[m-j][i];
				matrix[m-j][i] = matrix[m-i][m-j];
				matrix[m-i][m-j] = matrix[j][m-i];
				matrix[j][m-i] = temp;
			}
		}
    }
};

/* //For testing
int main(){
	Solution test;
	int arr[] = {1,2,3};
	vector<int> v;
	v.assign(arr,arr+3);

	vector<vector<int> > re;
	re.push_back(v);
	re.push_back(v);
	re.push_back(v);
	//re.push_back(v);
	test.rotate(re);
	for(int i=0; i<re.size(); i++){
		for(int k=0; k<re[i].size(); k++){
			cout << re[i][k] << " ";
		}
		cout << endl;
	}
	return 0;
}
*/
