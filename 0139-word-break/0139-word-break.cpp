class Solution {
private:
    bool helper(string s, int i, int j, vector<string>& wordDict) {
        if (dp[i][j] != -1) return dp[i][j];
        int n = s.size();
        string sub = s.substr(i, j - i + 1);
        bool found = find(wordDict.begin(), wordDict.end(), sub) != wordDict.end();
        if (j == n - 1) return dp[i][j] = found;
        if (found)
            return dp[i][j] = helper(s, i, j + 1, wordDict) || helper(s, j + 1, j + 1, wordDict);
        return dp[i][j] = helper(s, i, j + 1, wordDict);
    }
public:
    vector<vector<int>> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        dp = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
        return helper(s, 0, 0, wordDict);
    }
};