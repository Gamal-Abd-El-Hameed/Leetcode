class Solution {
private:
    void inorder(TreeNode* root, int &prev, int &minDiff) {
        if (!root)
            return;
        inorder(root->left, prev, minDiff);
        if (prev != -1)
            minDiff = min(minDiff, root->val - prev);
        prev = root->val;
        inorder(root->right, prev, minDiff);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX, prev = -1;
        inorder(root, prev, minDiff);
        return minDiff;
    }
};