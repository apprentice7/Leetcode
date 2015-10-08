// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Tony
// Date   : 08-10-1015

/********************************************************************************** 
* Validate if a given string is numeric.
* Some examples:
* "0" => true
* "   0.1  " => true
* "abc" => false
* "1 a" => false
* "2e10" => true
* Note: It is intended for the problem statement to be ambiguous. 
*       You should gather all requirements up front before implementing one.
**********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
	if(n<=0) return false; 
	bool eflag = false;
	bool dflag = false;
	int z = 0;

	//Delete white space and +/- sign at the beginning
	while(s[z] == ' '){
		s.erase(s.begin());
	}
	if(s[0] == '+' || s[0] == '-') s.erase(s.begin());

	//Delete white space at the end
	z=s.size()-1;
	while(s[z] == ' '){
		s.erase(s.begin()+z);
		z = s.size()-1;
	}

	n = s.size();
	if(n<=0) return false; 
	if(n==1 && (!isdigit(s[0]))) return false;

	for(int i=0; i<n; i++){
		if(isdigit(s[i])) continue;
		
		else if(s[i] == 'e'){
			if(eflag == false){ 
				if(!checkValidE(s,i,n)) return false;
				eflag = true;
			}
			else return false;
		}

		else if(s[i] == '.'){
			if(dflag == false){ 
				if(eflag == true) return false;
				dflag = true;
			}
			else return false;
		}

		else return false;
	}
	return true;
    }
    
    bool checkValidE(string &s, int i, int n){
	if(i==0 || i==n-1) return false;
	else if(!isdigit(s[i-1]) && i==1) return false;
	else if(!isdigit(s[i+1]) && i==n-2) return false;
	else if(i<n-2 ) {
		if(s[i+1]=='-' || s[i+1]=='+') s[i+1] = '1';
	}
	return true;
    }
};

/* //For testing
int main(){
	Solution test;
	string s = ".";
	cout << "false: " << endl;
	cout << test.isNumber(s) << endl;
	s = "..";
	cout << test.isNumber(s) << endl;
	s = "++";
	cout << test.isNumber(s) << endl;
	s = "+.";
	cout << test.isNumber(s) << endl;
	s = " 4e.3 ";
	cout << test.isNumber(s) << endl;

	cout << "true: " << endl;
	s = "46.e3";
	cout << test.isNumber(s) << endl;
	s = ".1";
	cout << test.isNumber(s) << endl;
	s = "+.1";
	cout << test.isNumber(s) << endl;
	s = "-.1";
	cout << test.isNumber(s) << endl;
	
	return 0;
}
*/
