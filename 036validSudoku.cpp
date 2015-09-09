// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 10-09-2015

/********************************************************************************** 
* Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
* The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
* A partially filled sudoku which is valid.
* Note:
* > A valid Sudoku board (partially filled) is not necessarily solvable. 
*   Only the filled cells need to be validated.
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		bool row[9][9] = {false};
		bool col[9][9] = {false};
		bool matrix[9][9] = {false};

		for(int r=0; r<board.size(); r++){
			for(int c=0; c<board.size(); c++){
				if(!isdigit(board[r][c])) continue;

				int num = board[r][c] - '0' - 1;
				if(row[r][num] == true) return false;
				row[r][num] = true;

				if(col[c][num] == true) return false;
				col[c][num] = true;

				int m = r/3 * 3 + c/3;
				if(matrix[m][num] == true) return false;
				matrix[m][num] = true;
			}
		}
		return true;
    }
};


/* //For testing
int main(){
	Solution test;

	return 0;
}
*/
