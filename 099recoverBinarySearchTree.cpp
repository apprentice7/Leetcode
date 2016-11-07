// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 30-09-2016

/********************************************************************************** 
* Two elements of a binary search tree (BST) are swapped by mistake.
* Recover the tree without changing its structure.
* Note:
* A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
public:
    void recoverTree(TreeNode* root) {
        inorderTree(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    
    void inorderTree(TreeNode* root) {
        if(!root) return;
        inorderTree(root->left);
        check(root);
        inorderTree(root->right);
    }
    
    void check(TreeNode* root) {
        if(prev == NULL) {
            prev = root;
            return;
        }
        if(prev->val > root->val && first == NULL) {
            first = prev;
            second = root;
        }
        else if(prev->val > root->val && first != NULL) {
        	second = root;
        }
        prev = root;
        return;
    }
};

int main() {
    Solution test;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->left->right = new TreeNode(2);
    
    test.recoverTree(root);
    cout << root->val << ", " << root->left->val << ", " << root->right->val << endl;
    return 0;
}
