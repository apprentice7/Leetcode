// Source : https://oj.leetcode.com/problems/sqrtx/
// Author : Tony Kang
// Date   : 15-10-2015

/********************************************************************************** 
* Implement int sqrt(int x).
* Compute and return the square root of x
**********************************************************************************/

#include <iostream>
using namespace std;

// http://en.wikipedia.org/wiki/Newton%27s_method
// Newton's law
int sqrt_nt(int x) {
    if (x == 0) return 0;
    double last = 0;
    double res = 1;
    while (res != last)
    {
        last = res;
        res = (res + x / res) / 2;
    }
    return int(res);
}

class Solution {
public:
    int mySqrt(int x) {
    if(x<=0) return 0;
		int lower = 0;
		int upper = x/2 + 1;

		while(lower <= upper){
			int root = (lower+upper)/2;

			long long sqr = (long long)root * (long long)root;
			if(sqr < x) lower = root + 1;
			else if(sqr > x) upper = root - 1;
			else{
				return root;
			}
		}
		return upper;
    }
};

/* //For testing
int main(){
	Solution test;
	cout << test.mySqrt(2147483647) << endl;

	return 0;
}
*/
