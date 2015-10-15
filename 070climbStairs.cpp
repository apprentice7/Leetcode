// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 15-10-2015

/********************************************************************************** 
* You are climbing a stair case. It takes n steps to reach to the top.
* Each time you can either climb 1 or 2 steps.
* In how many distinct ways can you climb to the top?
**********************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    if(n<4) return n;
		int twoPre = 2;
		int onePre = 3;
		int steps = 0;
		for(int i=3; i<n; i++){
			steps = twoPre+onePre;
			twoPre = onePre;
			onePre = steps;
		}
		return steps;
    }
};

/* //For testing
int main(){
	Solution test;
	cout<<test.climbStairs(5)<<endl;

	return 0;
}
*/
