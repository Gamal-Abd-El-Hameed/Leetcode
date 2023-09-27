class Solution {
private:
    void dfs(TreeNode* root, int num, int &sum) {
        num = 10 * num + root->val;
        if (!root->left && !root->right) {
            sum += num;
            return;
        }
        if (root->left)
            dfs(root->left, num, sum);
        if (root->right)
            dfs(root->right, num, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};