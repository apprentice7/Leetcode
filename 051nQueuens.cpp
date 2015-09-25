// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 25-09-2015

/********************************************************************************** 
* The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
* such that no two queens attack each other.
* Given an integer n, return all distinct solutions to the n-queens puzzle.
* Each solution contains a distinct board configuration of the n-queens' placement, 
* where 'Q' and '.' both indicate a queen and an empty space respectively.
* For example,
* There exist two distinct solutions to the 4-queens puzzle:
* [
*  [".Q..",  // Solution 1
*   "...Q",
*   "Q...",
*   "..Q."],
*  ["..Q.",  // Solution 2
*   "Q...",
*   "...Q",
*   ".Q.."]
* ]
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> 
using namespace std;

/*
idea refered from https://github.com/haoel/leetcode/blob/master/algorithms/nQueens/nQueuens.cpp
main difference with mine:
	1. use vector<int> solution(n) to represent the chess board
	2. assign the column number directly to solution[row]
in this way, this method reduce several loops and reduce the complexity
*/
class Solution {
public:
	vector< vector<string> > solveNQueens(int n) {
		vector< vector<string> > result;
		vector<int> solution(n);

	    solveNQueensRecursive(n, 0, solution, result);

	    return result;    
	}

	//The following recursion is easy to understand. Nothing's tricky.
	//  1) recursively find all of possible columns row by row.
	//  2) solution[] array only stores the columns index. `solution[row] = col;` 
	void solveNQueensRecursive(int n, int currentRow, vector<int>& solution, vector< vector<string> >& result) {
		//if no more row need to do, shape the result
		if (currentRow == n){
			vector<string> s;
			for (int row = 0; row < n; row++) {
				string sRow;
				for (int col = 0; col < n; col++) {
					sRow = sRow + (solution[row] == col ? "Q" :"." );
				}
				s.push_back(sRow);
			}
			result.push_back(s);
			return;
		}

		//for each column
		for (int col = 0; col < n; col++) {
			//if the current column is valid
			if (isValid(col, currentRow, solution) ) {
				//place the Queue
				solution[currentRow] = col;
				//recursively put the Queen in next row
				solveNQueensRecursive(n, currentRow+1, solution, result);
			}
		} 
	}

	//Attempting to put the Queen into [row, col], check it is valid or not
	//Notes: 
	//  1) we just checking the Column not Row, because the row cannot be conflicted
	//  2) to check the diagonal, we just check |x'-x| == |y'-y|, (x',y') is a Queen will be placed
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

//a stupid way that cannot pass time limit without refer to others
/*
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> chessRow;
		vector<vector<int> > chessBoard;
		vector<vector<string> > output;
		int x = -1;
		for(int i=0; i<n; i++){
			chessRow.push_back(x);
		}
		for(int i=0; i<n; i++){
			chessBoard.push_back(chessRow);
		}
		findQueenPosition(chessBoard, output, 0, n);
		return output;
    }

	void findQueenPosition(vector<vector<int> > chessBoard, vector<vector<string> >& output, int queenNum, int n){
		vector<vector<int> > tempBoard;
		int tempQueenNum;
		if(queenNum == n){
			vector<string> temp;
			for(int i=0; i<n; i++){
				string s;
				for(int j=0; j<n; j++){
					if(chessBoard[i][j] == 1){
						s += 'Q';
					}
					else{
						s += '.';
					}
				}
				temp.push_back(s);
			}
			for(int s=0; s<output.size(); s++){
				if(temp == output[s]) return;
			}
			output.push_back(temp);
			return;
		}
		//in chessBoard: 1-> Queen, 0-> Occupied, -1-> Vacant
		else{
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					tempBoard = chessBoard;
					tempQueenNum = queenNum;
					//chessBoard is vacant in this pos
					if(tempBoard[i][j] == -1){
						//put queen in this vacant position
						tempBoard[i][j] = 1;
						//set the colunm, row and skew into occupied
						for(int k=0; k<n; k++){
							if(tempBoard[i][k] == -1){
								tempBoard[i][k] = 0;
							}
							if(tempBoard[k][j] == -1){
								tempBoard[k][j] = 0;
							}
							for(int m=0; m<n; m++){
								if(isSkew(k, m, i, j)){
									tempBoard[k][m] = 0;
								}
							}
						}
						//add one to queenNum
						tempQueenNum++;
						//find next queen position
						findQueenPosition(tempBoard, output, tempQueenNum, n);
					}
					//chessBoard is occupied or queen
					else if(tempBoard[i][j] == 0 || tempBoard[i][j] == 1){
						
						//if(i==n-1 && j==n-1) return;
					}
					else {
						cout<<"error state found in chessBoard" << endl;
					}
				}
			}
		}
		return;
	}

	bool isSkew(int k, int m, int i, int j){
		int rowDiff, colDiff;
		rowDiff = abs(m - j);
		colDiff = abs(k - i);
		if(rowDiff == colDiff && rowDiff > 0){
			return true;
		}
		else{
			return false;
		}
	}
};
*/

/* //For testing
int main(){
	Solution test;
	int n = 6;
	vector<vector<string> > re;
	re = test.solveNQueens(n);
	for(int i=0; i<re.size(); i++){
		for(int j=0; j<re[i].size(); j++){
			cout << re[i][j] << endl;
		}
		cout << "next solution: " <<endl;
	}
	return 0;
}
*/
