class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int len = 0, maxLen = 0;
        for (int num:nums) {
            if (s.find(num - 1) == s.end()) {
                while (s.find(num) != s.end()) {
                    len++;
                    num++;
                }
                maxLen = max(len, maxLen);
                len = 0;
            }
        }
        return maxLen;
    }
};