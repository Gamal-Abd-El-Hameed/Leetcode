class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (const string& word : wordDict) {
                int wordLen = word.size();
                if (i >= wordLen && dp[i - wordLen] && s.substr(i - wordLen, wordLen) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
