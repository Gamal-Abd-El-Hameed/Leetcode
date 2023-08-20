class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool>dp(n, false);
        dp[0] = true;
        int jumps;
        for (int i = 1; i <= n; i++) {
            if (!dp[i - 1]) continue;
            jumps = nums[i - 1];
            for (int jump = 1; jump <= jumps && i - 1 + jump < n; jump++)
                dp[i - 1 + jump] = true;
        }
        return dp[n - 1];
    }
};