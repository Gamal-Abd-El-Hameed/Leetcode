class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        
        // Create dp array to store the LIS length ending at each index
        vector<int> dp(n, 1); // Initialize with 1 since every number is a valid subsequence of length 1
        
        int maxLength = 1; // Initialize the maximum length
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1); // Update LIS length at index i
                    maxLength = max(maxLength, dp[i]); // Update the maximum length
                }
            }
        }
        
        return maxLength;
    }
};
