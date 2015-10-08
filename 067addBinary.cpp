// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Tony
// Date   : 08-10-1015

/********************************************************************************** 
* Given two binary strings, return their sum (also a binary string).
* For example,
* a = "11"
* b = "1"
* Return "100".
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
    int n = a.size();
		int m = b.size();
		int len = max(n,m);
		int flag = 0;
		string output;
		string tmp;

		for(int i=0; i<abs(n-m); i++){
			tmp += '0';
		}
		if(n>m) b = tmp+b;
		else if(m>n) a = tmp + a;


		for(int i=len-1; i>=0; i--){
			int sum = (a[i]-'0') + (b[i]-'0') + flag;
			if(sum == 0){
				output += '0';
				flag = 0;
			}
			else if(sum == 1){
				output += '1';
				flag = 0;
			}
			else if(sum == 2){
				output += '0';
				flag = 1;
			}
			else if(sum == 3){
				output += '1';
				flag = 1;
			}
		}
		if(flag == 1) output += '1';
		reverse(output.begin(), output.end());
		return output;
    }
};

/* //For testing
int main(){
	Solution test;
	string a = "1111";
	string b = "1111";
	cout<< test.addBinary(a,b)<<endl;

	return 0;
}
*/
