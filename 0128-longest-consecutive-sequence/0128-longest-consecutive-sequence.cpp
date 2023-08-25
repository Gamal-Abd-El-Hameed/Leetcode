class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int len, maxLen = 0;
        for (int num:nums) {
            if (s.find(num - 1) == s.end()) {
                len = 0;
                do {
                    len++;
                } while (s.find(num + len) != s.end());
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};