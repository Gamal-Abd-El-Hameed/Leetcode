class Solution {
private:
    int rows, cols;
    vector<vector<int>> dp;
    int helper(int i, int j) {
        if (i == rows || j == cols) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (i == rows - 1 && j == cols - 1) return dp[i][j] = 1;
        return dp[i][j] = helper(i + 1, j) + helper(i, j + 1);
    }
public:
    int uniquePaths(int m, int n) {
        rows = m, cols = n;
        dp = vector<vector<int>>(rows, vector<int>(cols, -1));
        return helper(0, 0);
    }
};