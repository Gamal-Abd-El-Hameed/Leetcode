class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int len = 0, maxLen = 0;
        for (int num:nums) {
            if (s.find(num - 1) == s.end()) {
                do {
                    len++;
                    num++;
                } while (s.find(num) != s.end());
                maxLen = max(len, maxLen);
                len = 0;
            }
        }
        return maxLen;
    }
};