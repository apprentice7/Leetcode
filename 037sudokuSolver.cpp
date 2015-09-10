// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 11-09-2015

/********************************************************************************** 
* Write a program to solve a Sudoku puzzle by filling the empty cells.
* Empty cells are indicated by the character '.'.
* You may assume that there will be only one unique solution.
* A sudoku puzzle...
* ...and its solution numbers marked in red.              
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool row[9][9] = {false};
bool col[9][9] = {false};
bool matrix[9][9] = {false};

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        if(!isValidSudoku(board)) return;
		recursiveSudoku(board,0,0);
    }

	bool recursiveSudoku(vector<vector<char> >& board, int rowNum, int colNum){
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

	bool isValidSudoku(vector<vector<char> >& board) {
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

/* //For testing
int main(){
	Solution test;
	vector < vector<char> > v;
	vector<char> tt;
	char arr1[] = {'5','3','.','.','7','.','.','.','.'};
	char arr2[] = {'6','.','.','1','9','5','.','.','.'};
	char arr3[] = {'.','9','8','.','.','.','.','6','.'};
	char arr4[] = {'8','.','.','.','6','.','.','.','3'};
	char arr5[] = {'4','.','.','8','.','3','.','.','1'};
	char arr6[] = {'7','.','.','.','2','.','.','.','6'};
	char arr7[] = {'.','6','.','.','.','.','2','8','.'};
	char arr8[] = {'.','.','.','4','1','9','.','.','5'};
	char arr9[] = {'.','.','.','.','8','.','.','7','9'};
	
	tt.assign(arr1,arr1+9);
	v.push_back(tt);
	tt.assign(arr2,arr2+9);
	v.push_back(tt);
	tt.assign(arr3,arr3+9);
	v.push_back(tt);
	tt.assign(arr4,arr4+9);
	v.push_back(tt);
	tt.assign(arr5,arr5+9);
	v.push_back(tt);
	tt.assign(arr6,arr6+9);
	v.push_back(tt);
	tt.assign(arr7,arr7+9);
	v.push_back(tt);
	tt.assign(arr8,arr8+9);
	v.push_back(tt);
	tt.assign(arr9,arr9+9);
	v.push_back(tt);
	
	test.solveSudoku(v);
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cout << v[i][j] << " ";
			if(j == 8) cout << endl;
		}
	}
	return 0;
}
*/
