// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 11-08-2015


/***********************************************************************
* Determine whether an integer is a palindrome. 
* Do this without extra space.
* Some hints:
* Could negative integers be palindromes? (ie, -1)
* If you are thinking of converting the integer to string, note the restriction of using extra space.
* You could also try reversing an integer. 
* However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. 
* How would you handle such case?
* There is a more generic way of solving this problem.
***********************************************************************/

#include <iostream>
using namespace std;

class Solution{
public:
	bool isPalindrome(int x){
		if(x < 0) return false;
		int ToReverse = x;
		int reverse = 0;
		int digit = 0;;
		while(ToReverse!=0){
			digit = ToReverse % 10;
			reverse = reverse * 10 + digit;
			ToReverse = ToReverse / 10;
			
		}
		//cout << reverse << endl;
		//cout << x << endl;
		if(x == reverse){
			return true;
		}
		else{
			return false;	
		} 
	}
};
/* //for testing
int main(){
	int x = 123454321;
	Solution solution;
	bool result = solution.isPalindrome(x);
	cout << "result: " << result << endl;
	return 0;
}
*/
