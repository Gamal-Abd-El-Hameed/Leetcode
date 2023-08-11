class Solution {
public:
    vector<int> dp;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        
        dp = vector<int>(n, -1); // Initialize dp array with -1
        
        int maxLength = 1; // Initialize the maximum length
        
        for (int i = 0; i < n; i++) {
            maxLength = max(maxLength, LIS(nums, i));
        }
        
        return maxLength;
    }
private:
    int LIS(vector<int>& nums, int current_index) {
        if (dp[current_index] != -1) return dp[current_index];
        
        int max_length = 1; // Minimum length is 1 (considering only the element itself)
        
        for (int prev_index = 0; prev_index < current_index; prev_index++) {
            if (nums[current_index] > nums[prev_index]) {
                max_length = max(max_length, 1 + LIS(nums, prev_index));
            }
        }
        
        dp[current_index] = max_length; // Store the result in dp array
        return max_length;
    }
};
