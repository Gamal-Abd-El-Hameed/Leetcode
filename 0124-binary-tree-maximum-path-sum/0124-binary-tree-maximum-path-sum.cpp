class Solution {
private:
    int maxPathSum(TreeNode* root, int& maxSum) {
        if (!root) return 0;

        // Calculate the maximum path sum in the left and right subtrees
        int leftMax = max(0, maxPathSum(root->left, maxSum));
        int rightMax = max(0, maxPathSum(root->right, maxSum));

        // Calculate the maximum path sum passing through the current node
        int currentMax = root->val + leftMax + rightMax;

        // Update the global maximum sum if needed
        maxSum = max(maxSum, currentMax);

        // Return the maximum path sum starting from the current node
        return root->val + max(leftMax, rightMax);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // Initialize with the minimum possible value
        maxPathSum(root, maxSum);
        return maxSum;
    }
};