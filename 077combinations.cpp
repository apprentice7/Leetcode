// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 27-10-2015

/********************************************************************************** 
* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
* For example,
* If n = 4 and k = 2, a solution is:
* [
*   [2,4],
*   [3,4],
*   [2,3],
*   [1,2],
*   [1,3],
*   [1,4],
* ]
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
    vector<vector<int> >output;
		vector<int> temp;

		getComb(output, temp, 1, n, k);
		return output;
    }
	void getComb(vector<vector<int> >&output, vector<int> &temp, int a, int n, int k){
		if(k == 0) {
			output.push_back(temp);
			return;
		}
		else{
			for(int i=a; n-i+1>=k; i++){
				temp.push_back(i);
				getComb(output,temp,i+1,n,k-1);
				temp.pop_back();
			}
		}
	}
};

/* //For testing
int main(){
	Solution test;
	vector<vector<int> > re;
	re = test.combine(4,2);
	for(int i=0; i<(int)re.size();i++){
		for(int j=0; j<(int)re[i].size();j++){
			cout << re[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
*/
