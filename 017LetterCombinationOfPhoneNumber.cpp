// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 19-08-2015

/********************************************************************************** 
* 
* Given a digit string, return all possible letter combinations that the number could represent.
* A mapping of digit to letters (just like on the telephone buttons) is given below.
* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
* Note:
* Although the above answer is in lexicographical order, your answer could be in any order you want.
* 
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		char PhoneNum[10][4] = { 
		{' ','\0','\0','\0',},{'\0','\0','\0','\0',},{'a','b','c','\0',},
		{'d','e','f','\0'},{'g','h','i','\0'},{'j','k','l','\0'},
		{'m','n','o','\0'},{'p','q','r','s'},{'t','u','v','\0'},
		{'w','x','y','z'}
		};
		vector<string> output;
		for(int i=0; i<digits.size();i++){
			string temp;
			if(!isdigit(digits[i])) return output;
			int digit = digits[i] - '0';
			
			if (i == 0){
				for(int x=0; x<4; x++){
					if(PhoneNum[digit][x] == '\0'){
						break;
					}
					temp = PhoneNum[digit][x];
					output.push_back(temp);
				}
			}
			else{
				vector<string> tempout;
				for(int t=0; t<output.size(); t++){
					for(int x=0; x<4; x++){
						if(PhoneNum[digit][x] == '\0'){
							break;
						}
						temp = output[t]+PhoneNum[digit][x];
						tempout.push_back(temp);
					}
				}
				output = tempout;
				tempout.clear();
			}
		}
		return output;
    }
};
/* //For testing
int main(){
	Solution s;
  string test = "23";
	vector<string> re = s.letterCombinations(test);
	for(int tt=0;tt<re.size();tt++){
		cout << re[tt] << endl;
	}
	return 0;
}
*/
