class Solution {
    bool helper(TreeNode* root, long long low, long long high) {
        if(root == NULL)
            return true;
        int rootVal = root->val;
        if(rootVal <= low || rootVal >= high)
            return false;
        return helper(root->left, low, rootVal) && helper(root->right, rootVal, high);
    }
public:
bool isValidBST(TreeNode* root) {
        return helper(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};