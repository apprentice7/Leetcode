// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 08-08-2015

/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. 
If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

#include <iostream>
#include <string>
#include <math.h>
//#define INT_MAX 2147483647
//#define INT_MIN -2147483648
using namespace std;
class Solution{
public:
	int myAtoi(string str){
		int flag = 0;
		int result = 0;
		int para = 0;
		int i = 0;

		for(; i<str.size();i++){
			if(str[i] != ' '){
				break;
			}
		}
		//cout << "i: " << i << endl;
		if(str[i] == '-'){
			flag = -1;
			i++;
			cout << "h" << endl;
		}
		else if(str[i] == '+'){
			flag = 0;
			i++;
			cout << "e" << endl;
		}
		else if(!isdigit(str[i])){
			cout << "Not valid string" << endl;
			cout << "r" << endl;
			return 0;
		}
		if((str.size() - i - 1) > 10) {
			cout << "overflow/underflow" << endl;
			if(flag == -1) return INT_MIN;
			else if(flag == 0) return INT_MAX;
		}
		for(;i<str.size();i++){
			if(!isdigit(str[i])){
				cout << "Not valid string" << endl;
				return 0;
			}
			para = str.size() - i - 1;
			int digit = str[i] - '0';
			result = result + digit * pow(10,para);
		}
		if (flag == -1){
			result = -result;
		}
		return result;
	}	
};
/* //for testing
int main(){
	string s = "     -1546123";
	Solution solution;
	int x = solution.myAtoi(s);
	cout <<  "x: " << x << endl;
	return 0;
}
*/
