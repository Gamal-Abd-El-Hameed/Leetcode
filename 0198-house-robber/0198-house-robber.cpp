class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i - 1; j++) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
            dp[i] = max(dp[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
};