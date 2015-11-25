// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 25-11-2015

/********************************************************************************** 
* Given a binary tree, return the inorder traversal of its nodes' values.
* For example:
* Given binary tree {1,#,2,3},
*    1
*     \
*      2
*     /
*    3
* return [1,3,2].
* Note: Recursive solution is trivial, could you do it iteratively?
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

// A better iterative solution using stack:
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<TreeNode*> stack;
        vector<int> v;
        
        while(stack.size()>0 || root!=NULL){
            if (root!=NULL){
                stack.push_back(root);
                root = root->left;
            }else{
                if (stack.size()>0) {
                    root = stack.back();
                    stack.pop_back();
                    v.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return v;
    }
};
*/


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        if(root == NULL) return output;
        traversalHelper(root, output);
        return output;
    }
    void traversalHelper(TreeNode* node, vector<int> &output){
    	if(node->left == NULL){
    		output.push_back(node->val);
    		if(node->right == NULL){
    			return;
    		}
    		node = node->right;
    		traversalHelper(node, output);
    	}
    	else{
    		int temp = node->val;
    		TreeNode * l = node->left;
    		TreeNode * r = node->right;
    		//node = node->left;
    		traversalHelper(l, output);
    		output.push_back(temp);
    		if(node->right == NULL){
    			return;
    		}
    		traversalHelper(r,output);
    	}
    }
};

/* //For testing
int main(){
	Solution test;
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	TreeNode *d = new TreeNode(4);
	TreeNode *e = new TreeNode(5);
	TreeNode *f = new TreeNode(6);
	TreeNode *g = new TreeNode(7);
	TreeNode *h = new TreeNode(8);
	TreeNode *j = new TreeNode(9);
	f->left=b;
	f->right=g;
	b->left=a;
	b->right=d;
	d->left=c;
	d->right=e;
	g->right=j;
	j->left=h;

	vector<int> out;
	out = test.inorderTraversal(f);
	for(int i=0; i<out.size(); i++){
		cout<<out[i] << " ";
	}
	cout << endl;
	return 0;
}
*/
