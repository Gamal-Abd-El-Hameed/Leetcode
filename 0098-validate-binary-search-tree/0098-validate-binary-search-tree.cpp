class Solution {
private:
    bool isValidBSTHelper(TreeNode* root, long long low, long long high) {
        if (!root)
            return true;
        int rootVal = root->val;
        if (rootVal <= low || rootVal >= high)
            return false;
        return isValidBSTHelper(root->left, low, rootVal)
            && isValidBSTHelper(root->right, rootVal, high);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};