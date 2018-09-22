/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

TreeNode* treeing(TreeNode* root) {
    if (!root)
        return NULL;    
    
    root->left = treeing(root->left);
    root->right = treeing(root->right);
    
    if (root->val == 0 && !root->left && !root->right) {
        delete root;
        return NULL;
    }
    return root;
}

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) { 
        treeing(root);
        return root;
    }
};