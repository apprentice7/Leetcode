// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 24-08-2016

/********************************************************************************** 
* 
* Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
* 
* For example,
* Given n = 3, there are a total of 5 unique BST's.
* 
*    1         3     3      2      1
*     \       /     /      / \      \
*      3     2     1      1   3      2
* 
*               
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        //int* G = new int[n+1];
        vector<int> G(n+1, 0);
        G[0] = G[1] = 1;

        for(int i=2; i<=n; i++) {
        	for(int j=1; j<=i; j++) {
        		G[i] += G[j-1] * G[i-j];
        	}
        }

        return G[n];
    }
};

int main() {
	Solution test;
	cout << test.numTrees(3) << endl;
	return 0;
}