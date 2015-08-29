// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 29-08-2015

/********************************************************************************** 
* Divide two integers without using multiplication, division and mod operator.
* If it is overflow, return MAX_INT. 
**********************************************************************************/


#include <iostream>
#include <string>
using namespace std;

/*Solution written by haoel*/
class Solution{
public:
int divide(int dividend, int divisor) {
    int sign = (float)dividend / divisor > 0 ? 1 : -1;
    unsigned int dvd = dividend > 0 ? dividend : -dividend;
    unsigned int dvs = divisor > 0 ? divisor : -divisor;

    unsigned int bit_num[32];
    unsigned int i=0;
    long long d = dvs;
    bit_num[i] = d;
    while( d <= dvd ){
        bit_num[++i] = d = d << 1;
    }
    i--;
    unsigned int result = 0;
    while(dvd >= dvs){
        if (dvd >= bit_num[i]){
            dvd -= bit_num[i];
            result += (1<<i);
        }else{
            i--;
        }
    }
    //becasue need to return `int`, so we need to check it is overflowed or not.
    if ( result > INT_MAX && sign > 0 ) {
        return INT_MAX;
    }
    return (int)result * sign;
}
};



/* this solution cannot pass time limit requirement
class Solution {
public:
    int divide(int dividend, int divisor) {
    	if(divisor == 0) return -1;
        int sign = 0;
        if((float)dividend / divisor > 0) sign = 1;
        else sign = -1;
        if(dividend < 0) dividend = -dividend;
        if(divisor < 0) divisor = -divisor;

        long long output = 0;
        while(dividend >=  divisor){
        	dividend = dividend - divisor;
        	output++;
        }
        if(output > INT_MAX && sign >0) return INT_MAX;
        return (int) output * sign;
    }
};
*/

/* //For testing
int main(){
	Solution test;
	int result = 0;
	result = test.divide(-2147483648,-1);
	cout << result << endl;

	return 0;
}
*/
