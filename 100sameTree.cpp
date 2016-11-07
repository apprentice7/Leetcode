// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 01-10-2016

/********************************************************************************** 
* Given two binary trees, write a function to check if they are equal or not.
* Two binary trees are considered equal if they are structurally identical 
* and the nodes have the same value.
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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)) return false;
        if(p==NULL && q==NULL) return true;
        if(p->val != q->val) return false;
        else return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

int main() {
    Solution test;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->left->right = new TreeNode(5);
    
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(4);
    root1->right->left->right = new TreeNode(5);
    cout << test.isSameTree(root, root1) << endl;
    return 0;
}
