class Solution {
private:
    int n;
    vector<int>dp;
    bool isStringFrom10To26(string s) {
        return stoi(s) <= 26;
    }
    int helper(string s, int i) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        if (s[i] == '0') return dp[i] = 0;
        if (i == n - 1) return dp[i] = 1;
        int firstTaken = helper(s, i + 1);
        if (!isStringFrom10To26(s.substr(i, 2))) return dp[i] = firstTaken;
        int secondTaken;
        if (i == n - 2) secondTaken = 1;
        else secondTaken = helper(s, i + 2);
        return dp[i] = firstTaken + secondTaken;
    }
public:
    int numDecodings(string s) {
        n = s.length();
        dp.resize(n, -1);
        return helper(s, 0);
    }
};