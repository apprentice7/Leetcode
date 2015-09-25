// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 25-09-2015

/********************************************************************************** 
* Follow up for N-Queens problem.
* Now, instead outputting board configurations, return the total number of distinct solutions.
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> 
using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		vector<int> solution(n);
		int count = 0;
	    solveNQueensRecursive(n, 0, count, solution);
	    return count;    
	}

	void solveNQueensRecursive(int n, int currentRow, int& count, vector<int>& solution) {
		if (currentRow == n){
			count++;
			return;
		}	
		
		
		for (int col = 0; col < n; col++) {
			//if the current column is valid
			if (isValid(col, currentRow, solution) ) {
				//place the Queue
				solution[currentRow] = col;
				//recursively put the Queen in next row
				solveNQueensRecursive(n, currentRow+1, count, solution);
			}
		} 
	}

	bool isValid(int attemptedColumn, int attemptedRow, vector<int> &queenInColumn) {
		for(int i=0; i<attemptedRow; i++) {
		    if (attemptedColumn == queenInColumn[i]  || 
				abs(attemptedColumn - queenInColumn[i]) == abs(attemptedRow - i)) {
				return false;
			} 
		}
		return true;
	}
};

/* //For testing
int main(){
	Solution test;
	//int n = 6;
	//vector<vector<string> > re;
	cout << test.totalNQueens(6) << endl;;
	/*for(int i=0; i<re.size(); i++){
		for(int j=0; j<re[i].size(); j++){
			cout << re[i][j] << endl;
		}
		cout << "next solution: " <<endl;
	}*/
	return 0;
}
*/
