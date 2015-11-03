// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 03-11-2015

/********************************************************************************** 
* Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle 
* containing all ones and return its area.
**********************************************************************************/

/*idea adopted from: https://leetcode.com/discuss/20240/share-my-dp-solution */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
    const int m = matrix.size();
		if(m<1) return 0;
		const int n = matrix[0].size();
		int maxArea = 0;
		vector<int> left, right, height;
		for(int i=0; i<n; i++){
			left.push_back(0);
			right.push_back(n);
			height.push_back(0);
		}

		for(int i=0; i<m; i++){
			int leftBorder = 0;
			int rightBorder = n;
			for(int j=0; j<n; j++){
				if(matrix[i][j] == '1') height[j]++;
				else height[j] = 0;
			}
			for(int j=0; j<n; j++){
				if(matrix[i][j] == '1') left[j] = max(left[j],leftBorder);
				else{
					leftBorder = j+1;
					left[j] = 0;
				}
			}
			for(int j=n-1; j>=0; j--){
				if(matrix[i][j] == '1') right[j] = min(right[j], rightBorder);
				else{
					rightBorder = j;
					right[j] = n;
				}
			}

			for(int j=0; j<n; j++){
				maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
			}
		}
		return maxArea;
    }
};

/* //For testing
int main(){
	Solution test;
	char a[] = {'1','1','1','0','0'};
	char b[] = {'1','1','1','1','1'};
	char c[] = {'0','0','1','1','1'};
	char d[] = {'0','0','1','1','1'};
	vector<char> v;
	vector<vector<char> >re;
	v.assign(a,a+5);
	re.push_back(v);
	v.assign(b,b+5);
	re.push_back(v);
	v.assign(c,c+5);
	re.push_back(v);
	v.assign(d,d+5);
	re.push_back(v);
	cout << test.maximalRectangle(re) << endl;
	return 0;
}
*/
