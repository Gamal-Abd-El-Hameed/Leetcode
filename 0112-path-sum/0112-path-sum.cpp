class Solution {
private:
    bool hasPathSum(TreeNode* root, int targetSum, int currentSum) {
        if (!root->left && !root->right)
            return targetSum == currentSum;
        if (root->left && hasPathSum(root->left, targetSum, currentSum + root->left->val))
            return true;
        if (root->right)
            return hasPathSum(root->right, targetSum, currentSum + root->right->val);
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        return hasPathSum(root, targetSum, root->val);
    }
};