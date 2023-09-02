class Solution {
private:
    int maxPathSum(TreeNode* root, int& maxSum, unordered_map<TreeNode*, int>& dp) {
        if (!root) return 0;
        if (dp.count(root)) return dp[root];
        // Calculate the maximum path sum in the left and right subtrees
        int leftMax = max(0, maxPathSum(root->left, maxSum, dp));
        int rightMax = max(0, maxPathSum(root->right, maxSum, dp));

        // Calculate the maximum path sum passing through the current node
        int currentMax = root->val + leftMax + rightMax;

        // Update the global maximum sum if needed
        maxSum = max(maxSum, currentMax);

        // Return the maximum path sum starting from the current node
        return dp[root] = root->val + max(leftMax, rightMax);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // Initialize with the minimum possible value
        unordered_map<TreeNode*, int> dp;
        maxPathSum(root, maxSum, dp);
        return maxSum;
    }
};