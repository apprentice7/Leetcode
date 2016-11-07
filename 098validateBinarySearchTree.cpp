// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 28-09-2016

/********************************************************************************** 
* Given a binary tree, determine if it is a valid binary search tree (BST).
* Assume a BST is defined as follows:
* The left subtree of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.
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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
	TreeNode* prev = NULL;
public:
    bool isValidBST(TreeNode* root) {
    	if(!root) return true;
    	return isValidBST(root->left) && check(root) && isValidBST(root->right);
    }

    bool check(TreeNode* root) {
    	if(!prev) {
    		prev = root;
    		return true;
    	}
    	if(prev->val < root->val) {
    		prev = root;
    		return true;
    	} 
    	return false;
    }
};


int main() {
	Solution test;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->left->right = new TreeNode(5);

	cout << test.isValidBST(root) << endl;
	return 0;
}