// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 07-08-2015


/***********************************************************************
* Reverse digits of an integer.

* Example1: x = 123, return 321
* Example2: x = -123, return -321
***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	int reverse(int x){
		string s;
		string out;
		int result;
		if(x > 0){
			s = to_string(x);
			for(int i = 0; i<s.size();i++){
				out[i] = s[s.size()-i-1];
			}
			result = stoi(out);
		}
		else{
			x = -x;
			s = to_string(x);
			for(int i = 0; i<s.size();i++){
				out[i] = s[s.size()-i-1];
			}
			result = -stoi(out);
		}
		return result;
	}
};

/* //for testing
int main(){
	int x = 123456789;
	int y = -123123456;
	Solution solution;
	int re1 = solution.reverse(x);
	int re2 = solution.reverse(y);
	cout << "re1: " << re1 << endl;
	cout << "re2: " << re2 << endl;
}
*/
