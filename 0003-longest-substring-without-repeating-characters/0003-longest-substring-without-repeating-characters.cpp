class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_set<char> visited;
        int start = 0, end = 0, n = s.size(), ans = 0;
        while (end < n) {
            if (visited.find(s[end]) == visited.end()) {
                visited.insert(s[end]);
                ans = max(ans, end - start + 1);
                end++;
            }
            else {
                visited.erase(s[start]);
                start++;
            }
        }
        return ans;
    }
};