// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 01-10-2016

/********************************************************************************** 
* Given a binary tree, return the level order traversal of its nodes' values. 
* (ie, from left to right, level by level).
* For example:
* Given binary tree {3,9,20,#,#,15,7},
*     3
*    / \
*   9  20
*     /  \
*    15   7
* return its level order traversal as:
* [
*   [3],
*   [9,20],
*   [15,7]
* ]
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > LOContainer;
        if(root == NULL) return LOContainer;
        
        vector<TreeNode*> treeNodes;
        treeNodes.push_back(root);
        levelOrderParse(treeNodes, LOContainer);
        return LOContainer;
    }

    void levelOrderParse(vector<TreeNode*> treeNodes, vector<vector<int> > &LOContainer){
        if(treeNodes.empty()) return;
        vector<TreeNode*> tempNodes;
        vector<int> levelContainer;
        while(!treeNodes.empty()){
            TreeNode* temp = treeNodes.front();
            if(temp->left != NULL) tempNodes.push_back(temp->left);
            if(temp->right != NULL) tempNodes.push_back(temp->right);
            levelContainer.push_back(temp->val);
            treeNodes.erase(treeNodes.begin());         
        }
        LOContainer.push_back(levelContainer);
        levelOrderParse(tempNodes, LOContainer);
    }
};

int main() {
    Solution test;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    //root->left->left = new TreeNode(3);
    //root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(17);
    
    vector<vector<int> > L;
    L = test.levelOrder(root);
    for(int i=0; i<L.size(); i++) {
        for(int j=0; j<L[i].size(); j++) {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
