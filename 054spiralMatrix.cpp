// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 29-09-2015

/********************************************************************************** 
* Given a matrix of m x n elements (m rows, n columns), 
* return all elements of the matrix in spiral order.
* For example,
* Given the following matrix:
* [
*  [ 1, 2, 3 ],
*  [ 4, 5, 6 ],
*  [ 7, 8, 9 ]
* ]
* You should return [1,2,3,6,9,8,7,4,5].
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> output;
		int m=matrix.size();
		if(m<1) return output;
        int n=matrix[0].size();
		if(n<1) return output;
        int i = 0;
        int j = 0;
        
        vector<bool> temp;
        vector<vector<bool> > mark;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                temp.push_back(true);
            }
            mark.push_back(temp);
			temp.clear();
        }
        
        while(i<(m+1)/2 && j<(n+1)/2){
			int row=i;
			int col=j;
			//horizontal increase
			while(col<n && mark[row][col]==true){
				output.push_back(matrix[row][col]);
				mark[row][col] = false;
				col++;
			}
			col--;
			row++;
			//vertical increase
            while(row<m && mark[row][col]==true){
				output.push_back(matrix[row][col]);
				mark[row][col] = false;
				row++;
			}
			row--;
			col--;
			//horizontal decrease
			while(col>=0 && mark[row][col]==true){
				output.push_back(matrix[row][col]);
				mark[row][col] = false;
				col--;
			}
			col++;
			row--;
			//vertical decrease
			while(row>0 && mark[row][col]==true){
				output.push_back(matrix[row][col]);
				mark[row][col] = false;
				row--;
			}
			i++;
			j++;
        }
        return output;
    }
};

/* //For testing
int main(){
    Solution test;
    vector<vector<int> > input;
    vector<int> v;
    int arr1[]={1,2,3};
    int arr2[]={4,5,6};
    int arr3[]={7,8,9};
    v.assign(arr1,arr1+3);
    input.push_back(v);
    v.assign(arr2,arr2+3);
    input.push_back(v);
    v.assign(arr3,arr3+3);
    input.push_back(v);

    v = test.spiralOrder(input);
    for(int i=0; i< v.size(); i++){
        cout<<v[i]<< " ";
    }
    return 0;
}
*/
