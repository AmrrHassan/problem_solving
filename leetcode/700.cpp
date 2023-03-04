// Runtime 48 ms Beats 42.74%
// Memory 34.8 MB Beats 71.5%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root || ( root->val == val )) return root;
        if(root->val < val) return searchBST(root->right,val);
        else return searchBST(root->left,val);
    }
};