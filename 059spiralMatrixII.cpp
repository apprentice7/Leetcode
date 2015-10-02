// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 02-10-2015

/********************************************************************************** 
* Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
* For example,
* Given n = 3,
* You should return the following matrix:
* [
*  [ 1, 2, 3 ],
*  [ 8, 9, 4 ],
*  [ 7, 6, 5 ]
* ]
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > output;
		vector<int> tmp;
		int count = 0;
		int num = 0;
		int i=0;
		int j=0;

		for(int d=0; d<n; d++){
			for(int e=0; e<n; e++){
				tmp.push_back(0);
			}
			output.push_back(tmp);
			tmp.clear();
		}

		while(count <= (n-1)/2){
			i = j = count;
			while(j<n && output[i][j] == 0) {
				num++;
				output[i][j] = num;
				j++;
			}
			j--;
			i++;
			while(i<n && output[i][j] == 0){
				num++;
				output[i][j] = num;
				i++;
			}
			i--;
			j--;
			while(j>-1 && output[i][j] == 0){
				num++;
				output[i][j] = num;
				j--;
			}
			j++;
			i--;
			while(i>0 && output[i][j] == 0){
				num++;
				output[i][j] = num;
				i--;
			}
			count++;
		}
		return output;
    }
};

/* //For testing
int main(){
    Solution test;
	vector<vector<int> > re;
	int n = 4;
	re = test.generateMatrix(n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << re[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}
*/
