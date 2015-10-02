// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 02-10-2015

/********************************************************************************** 
* The set [1,2,3,…,n] contains a total of n! unique permutations.
* By listing and labeling all of the permutations in order,
* We get the following sequence (ie, for n = 3):
* "123"
* "132"
* "213"
* "231"
* "312"
* "321"
* Given n and k, return the kth permutation sequence.
* Note: Given n will be between 1 and 9 inclusive.
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
idea: determine the permutation by digit.
for every digit in n's position(from right to left), there are （n-1)！permutation
by k-(n-1)！we can loop to find every digit.
*/

class Solution {
public:
    string getPermutation(int n, int k) {
    int temp = 0;
		int num = 0;
		int size = n;
		string output;
		bool flag = false;

		vector<bool> check;
		for(int i=0; i<n; i++){
			check.push_back(true);
		}
		
		while(n>0){
			num = 0;
			temp = fac(n-1);
			n = n-1;
			while(k>temp){
				num++;
				k -= temp;
				flag = true;
			}
			if(flag == false){
				for(int i=0; i<size; i++){
					if(check[i] == true){
						output += (i+1)+'0';
						check[i] = false;
						break;
					}
				}
			}
			else{
				int c = -1;
				while(num>=0){
					c++;
					if(check[c] == true) num--;
				}
				check[c] = false;
				output += c+1+'0';
				flag = false;
			}
		}
		return output;
    }

	int fac(int x){
		int re;
		if(x==0 || x==1){
			re=1;
		}
		else{
			re = fac(x-1) * x;
		}
		return re;
	}
};

/* //For testing
int main(){
  Solution test;
	string re;
	re = test.getPermutation(4,3);
	cout << re << endl;
    return 0;
}
*/
