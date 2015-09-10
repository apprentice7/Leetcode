// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 10-09-2015



#include <iostream>
#include <vector>
using namespace std;

bool row[9][9] = {false};
bool col[9][9] = {false};
bool matrix[9][9] = {false};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(!isValidSudoku(board)) return;
		recursiveSudoku(board,0,0);
    }

	bool recursiveSudoku(vector<vector<char>>& board, int rowNum, int colNum){
		if(rowNum>=9) return true;
		if(colNum>=9) return recursiveSudoku(board, rowNum+1, 0);
		if(board[rowNum][colNum] != '.') return recursiveSudoku(board,rowNum,colNum+1);

		int area=0;
		for(int i=0; i<9; i++){
			area = rowNum/3 * 3 + colNum/3;
			if(row[rowNum][i] || col[colNum][i] || matrix[area][i]) continue;

			board[rowNum][colNum] = i + '1';
			row[rowNum][i] = true;
			col[colNum][i] = true;
			matrix[area][i] = true;

			if(recursiveSudoku(board,rowNum,colNum+1)) return true;

			board[rowNum][colNum] = '.';
			row[rowNum][i] = false;
			col[colNum][i] = false;
			matrix[area][i] = false;

		}
		return false;
	}

	bool isValidSudoku(vector<vector<char>>& board) {
		for(int r=0; r<board.size(); r++){
			for(int c=0; c<board.size(); c++){
				if(!isdigit(board[r][c])) continue;
				int num = board[r][c] - '0' - 1;
				int m = r/3 * 3 + c/3;
				if(row[r][num] || col[c][num] || matrix[m][num]) return false;
				row[r][num] = true;
				col[c][num] = true;
				matrix[m][num] = true;
			}
		}
		return true;
    }
};

 //For testing
int main(){
	Solution test;
	string arr1[]={"5","3",".",".",}
	string arr[] = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
	vector<int> v;
	v.assign(arr,arr+9);
	test.solveSudoku(v);

	return 0;
}
