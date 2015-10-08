// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Tony
// Date   : 08-10-1015

/**********************************************************************************
* Given a non-negative number represented as an array of digits, plus one to the number
* The digits are stored such that the most significant digit is at the head of the list.
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
		if(n<=0) return digits;

		for(int i=n-1; i>=0; i--){
			int t = digits[i] + 1;
			if(t<=9){
				digits[i] = t;
				return digits;
			}
			else{
				digits[i] = 0;
			}
		}
		digits.insert(digits.begin(), 1);
		return digits;
    }
};

/* //For testing
int main(){
	Solution test;
	int arr[] ={9,9,9};
	vector<int> v;
	v.assign(arr,arr+3);
	vector<int> re;
	re = test.plusOne(v);
	for(int i=0; i<re.size(); i++){
		cout<<re[i];
	}
	
	return 0;
}
*/
