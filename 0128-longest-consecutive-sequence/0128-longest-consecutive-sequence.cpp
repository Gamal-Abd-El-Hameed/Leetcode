class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int len = 1, maxLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue;
            if (nums[i] - nums[i - 1] == 1) {
                len++;
            }
            else {
                maxLen = max(maxLen, len);
                len = 1;
            }
        }
        return max(maxLen, len);
    }
};