// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 16-08-2015

/********************************************************************************** 
* 
* Given a roman numeral, convert it to an integer.
* 
* Input is guaranteed to be within the range from 1 to 3999.
*               
**********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	int romanToInt(string s){
		int out = 0;
		for(int i = 0; i<s.size();i++){
			if(s[i] == 'M'){
				out=out+1000;
			}
			else if(s[i]=='C' && s[i+1]=='M'){
				out = out + 900;
				i++;
			}
			else if(s[i] == 'D'){
				out = out + 500;
			}
			else if(s[i] == 'C' && s[i+1] == 'D'){
				out = out + 400;
				i++;
			}
			else if(s[i] == 'C'){
				out = out + 100;
			}
			else if(s[i] == 'X' && s[i+1] == 'C'){
				out = out + 90;
				i++;
			}
			else if(s[i] == 'L'){
				out = out + 50;
			}
			else if(s[i] == 'X' && s[i+1] == 'L'){
				out = out + 40;
				i++;
			}
			else if(s[i] == 'X'){
				out = out + 10;
			}
			else if(s[i] == 'I' && s[i+1] == 'X'){
				out = out + 9;
				i++;
			}
			else if(s[i] == 'V'){
				out = out + 5;
			}
			else if(s[i] == 'I' && s[i+1] == 'V'){
				out = out + 4;
				i++;
			}
			else if(s[i] == 'I'){
				out = out + 1;
			}
			else{
				cout << i << endl;
				return 0;
			}
		}
		return out;
	}
};

/* //For testing
int main(){
	string s = "MMMCCCXCVIII";
	Solution solution;
	int result = 0;
	result = solution.romanToInt(s);
	cout << "result: " << result << endl;
	return 0;
}
*?
