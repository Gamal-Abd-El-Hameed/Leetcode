
class Solution {
private:
    bool helper(string s, vector<string>& wordDict, int i) {
        if (i == s.size()) return true;
        if (dp[i] != -1) return dp[i];
        string subsetString;
        for (const string& word : wordDict) {
            subsetString = s.substr(i, word.size());
            if (word == subsetString) {
                dp[i] = helper(s, wordDict, i + word.size());
                if (dp[i]) return true;
            }
        }
        return dp[i] = false;
    }
public:
    vector<int> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.size(), -1);
        return helper(s, wordDict, 0);
    }
};
