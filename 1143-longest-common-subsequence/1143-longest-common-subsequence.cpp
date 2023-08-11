class Solution {
public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
         dp.resize(text1.size(), vector<int>(text2.size()));
         for (int i = 0; i < n1; i++)
             for (int j = 0; j < n2; j++)
                 if (text1[i] == text2[j]) {
                     if (i == 0 || j == 0)
                         dp[i][j] = 1;
                     else
                         dp[i][j] = 1 + dp[i - 1][j - 1];
                 }
                 else {
                     if (i == 0 && j == 0)
                         dp[i][j] = 0;
                     else if (i == 0)
                         dp[i][j] = dp[i][j - 1];
                     else if (j == 0)
                         dp[i][j] = dp[i - 1][j];
                     else {
                         dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                     }
                 }
        return dp[n1 - 1][n2 - 1];
    }
};