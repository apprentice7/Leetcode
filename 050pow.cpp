// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 24-09-2015

/********************************************************************************** 
* Implement pow(x, n).
**********************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
		//flag to indicate pos/neg of n
        bool flag = false;
		//int to conver n into positive number
		unsigned int exp = n;
		if(n<0){
			exp = -n;
			flag = true;
		}
		double re = 1.0;
		//loop n until n==0
		while(exp){
			//if n is odd number
			if((exp%2)!=0){
				//result = result * x
				re = re*x;
			}
			//exp divided by 2 because every loop we set x=x*x
			//in this way we can deduct the times of loop into binary
			exp >>=1;
			x =x*x;
		}
		if(flag==true) return 1/re;
		else return re;
    }
};
/* //For testing
int main(){
	Solution test;
	cout <<test.myPow(8.88023,3)<<endl;

	return 0;
}
*/
