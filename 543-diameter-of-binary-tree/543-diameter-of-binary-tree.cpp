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
    pair<int, int> helper(TreeNode* root) {
    if(root == NULL)
        return {0,0};
    pair<int,int> p;
    pair<int,int> left = helper(root->left);
    pair<int,int> right = helper(root->right);
    p.first = 1 + max(left.first, right.first);
    p.second = max(left.first + right.first, max(left.second, right.second));
    return p;
}

int diameterOfBinaryTree(TreeNode* root) {
    return helper(root).second;
}
};