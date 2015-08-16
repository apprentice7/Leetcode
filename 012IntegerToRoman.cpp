// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 16-08-2015

/********************************************************************************** 
* 
* Given an integer, convert it to a roman numeral.
* 
* Input is guaranteed to be within the range from 1 to 3999.
*               
**********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//greedy algorithm: is an algorithm that follows the problem solving heuristic of 
//making the locally optimal choice at each stage with the hope of finding a global optimum.

/*
string symbol[] =   {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};    
    int value[]     =   {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1}; 
    string result;

    for(int i=0; num!=0; i++){
        while(num >= value[i]){
            num -= value[i];
            result+=symbol[i];
        }
    }

    return result;
*/

class Solution{
public:
	string intToRoman(int num){
		int x = 0;
		string Numtoint;
		string out;

		Numtoint = to_string(num);
		x = Numtoint.size();
		if(num <= 0 || num > 3999){
			return "Not Valid String";
		}
		else{
			return ConvertNum(num, out, x);
		}
	}
private:
	string ConvertNum(int n, string t, int x){
		if(x == 1){
			if(n == 1){
				t.append("I");
			}
			if(n == 2){
				t.append("II");
			}
			if(n == 3){
				t.append("III");
			}
			if(n == 4){
				t.append("IV");
			}
			if(n == 5){
				t.append("V");
			}
			if(n == 6){
				t.append("VI");
			}
			if(n == 7){
				t.append("VII");
			}
			if(n == 8){
				t.append("VIII");
			}
			if(n == 9){
				t.append("IX");
			}
			return t;
		}
		if(x == 2){
			int re = 0;
			re = n / 10;
			if(re == 1){
				t.append("X");
			}
			if(re == 2){
				t.append("XX");
			}
			if(re == 3){
				t.append("XXX");
			}
			if(re == 4){
				t.append("XL");
			}
			if(re == 5){
				t.append("L");
			}
			if(re == 6){
				t.append("LX");
			}
			if(re == 7){
				t.append("LXX");
			}
			if(re == 8){
				t.append("LXXX");
			}
			if(re == 9){
				t.append("XC");
			}
			n = n - 10 * re;
			return ConvertNum(n,t,1);
		}
		if(x == 3){
			int re = 0;
			re = n / 100;
			if(re == 1){
				t.append("C");
			}
			if(re == 2){
				t.append("CC");
			}
			if(re == 3){
				t.append("CCC");
			}
			if(re == 4){
				t.append("CD");
			}
			if(re == 5){
				t.append("D");
			}
			if(re == 6){
				t.append("DC");
			}
			if(re == 7){
				t.append("DCC");
			}
			if(re == 8){
				t.append("DCCC");
			}
			if(re == 9){
				t.append("CM");
			}
			n = n - 100 * re;
			return ConvertNum(n,t,2);
		}
		if(x == 4){
			int re = 0;
			re = n / 1000;
			if(re == 1){
				t.append("M");
			}
			if(re == 2){
				t.append("MM");
			}
			if(re == 3){
				t.append("MMM");
			}
			n = n - 1000 * re;
			return ConvertNum(n,t,3);
		}
		else{
			return "Not Valid String";
		}
	}
};
/* //For testing
int main(){
	int test = 3999;
	string result;
	Solution s;
	result = s.intToRoman(test);
	cout << "result: " << result << endl;
	return 0;
}
*/
