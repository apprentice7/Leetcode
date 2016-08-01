// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 01-08-2016

/********************************************************************************** 
* Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
* For example,
* Given n = 3, your program should return all 5 unique BST's shown below.
* 
*    1         3     3      2      1
*     \       /     /      / \      \
*      3     2     1      1   3      2
* 
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
* OJ's Binary Tree Serialization:
* The serialization of a binary tree follows a level order traversal, where '#' signifies 
* a path terminator where no node exists below.
* Here's an example:
*    1
*   / \
*  2   3
*     /
*    4
*     \
*      5
* The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".         
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
    	if(n <= 0) return vector<TreeNode*> ();;
    	return generateTrees(1, n);
    }

private:
	vector<TreeNode*> generateTrees(int start, int end) {
		vector<TreeNode*> result;
		if(start > end) {
			result.push_back(NULL);
			return result;
		}
		if(start == end) {
			result.push_back(new TreeNode(start));
			return result;
		}
		vector<TreeNode*> left, right;
		for(int i=start; i<=end; i++) {
			left = generateTrees(start, i-1);
			right = generateTrees(i+1, end);
			for(auto lnode : left) {
				for(auto rnode : right) {
					TreeNode* root = new TreeNode(i);
					root->left = lnode;
					root->right = rnode;
					result.push_back(root);
				}
			}
		}
		return result;
	}
};

/* unit testing */
int main() {
	Solution test;
	vector<TreeNode*> testing = test.generateTrees(3);
	for(int i=0; i<testing.size(); i++) {
		cout << testing[i]->val << endl;
	}
	return 0;
}




