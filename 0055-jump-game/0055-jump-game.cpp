class Solution {
private:
    int n;
    vector<int>dp;
    bool helper(vector<int>& nums, int i) {
        if (i == n) return false;
        if (i == n - 1) return dp[i] = true;
        if (dp[i] != -1) return dp[i];
        int jumps = nums[i];
        for (int jump = 1; jump <= jumps; jump++) {
            bool trial = helper(nums, i + jump);
            if (trial) return dp[i] = true;
        }
        return dp[i] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, -1);
        return helper(nums, 0);
    }
};