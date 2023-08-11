class Solution {
private:
    int helper(const string &str1, const string &str2, int i, int j) {
        if (i == -1 || j == -1) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (str1[i] == str2[j])
            dp[i][j] = 1 + helper(str1, str2, i - 1, j - 1);
        else
            dp[i][j] = max(helper(str1, str2, i - 1, j),
                           helper(str1, str2, i, j - 1));
        return dp[i][j];
    }
public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
         dp.resize(text1.size(), vector<int>(text2.size(), -1));
        return helper(text1, text2, text1.size() - 1, text2.size() - 1);
    }
};