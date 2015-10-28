// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 28-10-2015

/********************************************************************************** 
* Given a 2D board and a word, find if the word exists in the grid.
* The word can be constructed from letters of sequentially adjacent cell, 
* where "adjacent" cells are those horizontally or vertically neighboring. 
* The same letter cell may not be used more than once.
* For example,
* Given board = 
* [
*   ["ABCE"],
*   ["SFCS"],
*   ["ADEE"]
* ]
* word = "ABCCED", -> returns true,
* word = "SEE", -> returns true,
* word = "ABCB", -> returns false.
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
		bool re;
		re = findWord(board, word, 0, 0, 0);
		return re;
    }
private:
	bool findWord(vector<vector<char> >&board, string word, int strPos, int rPos, int cPos){
		int n = board.size();
		int m = board[0].size();
		int s = word.size();

		if(strPos == 0){
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					if(board[i][j] == word[strPos] && board[i][j]!=' '){
						board[i][j] = ' ';
						if(findWord(board,word,strPos+1,i,j)) return true;
						else board[i][j] = word[strPos];
					}
				}
			}
			return false;
		}
		else if(strPos >= s){
			return true;
		}
		else{
			//up
			if(rPos>0 && board[rPos-1][cPos] == word[strPos] && board[rPos-1][cPos]!=' '){
				board[rPos-1][cPos] = ' ';
				if(findWord(board,word,strPos+1,rPos-1,cPos)) return true;
				else board[rPos-1][cPos] = word[strPos];
			}
			//down
			if(rPos<n-1 && board[rPos+1][cPos] == word[strPos] && board[rPos+1][cPos]!=' '){
				board[rPos+1][cPos] = ' ';
				if(findWord(board,word,strPos+1,rPos+1,cPos)) return true;
				else board[rPos+1][cPos] = word[strPos];
			}
			//left
			if(cPos>0 && board[rPos][cPos-1] == word[strPos] && board[rPos][cPos-1]!=' '){
				board[rPos][cPos-1] = ' ';
				if(findWord(board,word,strPos+1,rPos,cPos-1)) return true;
				else board[rPos][cPos-1] = word[strPos];
			}
			//right
			if(cPos<m-1 && board[rPos][cPos+1] == word[strPos] && board[rPos][cPos+1]!=' '){
				board[rPos][cPos+1] = ' ';
				if(findWord(board,word,strPos+1,rPos,cPos+1)) return true;
				else board[rPos][cPos+1] = word[strPos];
			}
			return false;
		}
	}
};

/* //For testing
int main(){
	Solution test;
	vector<vector<char> > re;
	vector<char> tmp;
	char a[] ={'A','B','C','E'};
	char b[] ={'S','F','C','S'};
	char c[] ={'A','D','E','E'};
	//char d[] ={'A','B','C','E'};
	tmp.assign(a,a+4);
	re.push_back(tmp);
	tmp.assign(b,b+4);
	re.push_back(tmp);
	tmp.assign(c,c+4);
	re.push_back(tmp);
	string t = "ABCB";

	for(int i=0; i<(int)re.size();i++){
		for(int j=0; j<(int)re[i].size();j++){
			cout << re[i][j] << " ";
		}
		cout << endl;
	}

	cout << test.exist(re,t) << endl;
	return 0;
}
*/
