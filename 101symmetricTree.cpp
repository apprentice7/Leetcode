// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 01-10-2016

/********************************************************************************** 
* Given a binary tree, check whether it is a mirror of itself 
* (ie, symmetric around its center).
* For example, this binary tree is symmetric:
*     1
*    / \
*   2   2
*  / \ / \
* 3  4 4  3
* But the following is not:
*     1
*    / \
*   2   2
*    \   \
*    3    3
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return symmetricTraverse(root->left, root->right);
    }

    bool symmetricTraverse(TreeNode* p, TreeNode* q) {
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)) return false;
        if(p==NULL && q==NULL) return true;
        if(p->val != q->val) return false;
        return (symmetricTraverse(p->left, q->right) 
            && symmetricTraverse(p->right, q->left));
    }
};

int main() {
    Solution test;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    
    cout << test.isSymmetric(root) << endl;
    return 0;
}
