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
    pair<bool, int> helper(TreeNode* root) {
        if(root == NULL)
            return {true, 0};
        pair<bool, int> left = helper(root->left);
        pair<bool, int> right = helper(root->right);
        int h1 = left.second, h2 = right.second;
        bool f = left.first && right.first && abs(h1 - h2) <= 1;
        return {f, 1 + max(h1, h2)};
    }
public:    
    bool isBalanced(TreeNode* root) {
        return helper(root).first;
    }
};