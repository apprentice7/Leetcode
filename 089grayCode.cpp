// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 09-11-2015

/********************************************************************************** 
* The gray code is a binary numeral system where two successive values differ in only one bit.
* Given a non-negative integer n representing the total number of bits in the code, 
* print the sequence of gray code. A gray code sequence must begin with 0.
* For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
* 00 - 0
* 01 - 1
* 11 - 3
* 10 - 2
* Note:
* For a given n, a gray code sequence is not uniquely defined.
* For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
* For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
**********************************************************************************/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/* A very smart way in mathematics:  (num >> 1) ^ num; 
  http://en.wikipedia.org/wiki/Gray_code 
*/

class Solution {
public:
	vector<int> grayCode(int n) {         
	    vector<int> ret;   
	    int size = 1 << n;   
	    for(int i = 0; i < size; ++i) {
	        ret.push_back((i >> 1)^i);   
	    }
	    return ret;   
	}
};



/* A very stupid way by myself*/
class Solution {
public:
    vector<int> grayCode(int n) {
    vector<int> output;
		if(n == 0) {
			output.push_back(0);
			return output;
		}
		vector<int> next;
		for(int i=0; i<n; i++){
			next.push_back(0);
		}
		appendGrayCode(output, next, n, 0);
		
		return output;
    }
private:
	void appendGrayCode(vector<int> &output, vector<int> next, int n, int size){
		bool flag = false;
		if(size == pow(2.0,n)) return;
		int temp = toNum(next);
		for(int i=0; i<output.size(); i++){
			if(output[i] == temp) {
				flag = true; //found 'next' in output
				break;
			}
		}
		if(flag == false){ //not found in output
			output.push_back(temp);
			for(int i=n-1; i>=0; i--){
				if(next[i] == 0){
					next[i] = 1;
					appendGrayCode(output, next, n, size+1);
					next[i] = 0;
				}
				else if(next[i] == 1){
					next[i] = 0;
					appendGrayCode(output, next, n, size+1);
					next[i] = 1;
				}
			}
		}
	}
	int toNum(vector<int> oct){
		int re = 0;
		int n = oct.size();
		int j = 0;
		for(int i=n-1; i>=0; i--,j++){
			if(oct[i] == 0) continue;
			re = re + pow(2.0, j);
		}
		return re;
	}
};

/* //For testing
int main(){
	Solution test;	
	vector<int> re; 
	re = test.grayCode(3);

	for(int i=0; i<re.size(); i++){
		cout << re[i] << endl;
	}
	return 0;
}
*/
