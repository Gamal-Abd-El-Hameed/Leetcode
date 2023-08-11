class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0].push_back(vector<int>());
        vector<vector<int>> sub;
        for (int i = 1; i <= target; i++) {
            for (int candidate : candidates) {
                if (candidate <= i) {
                    sub = dp[i - candidate];
                    if (!sub.empty()) {
                        for (vector<int> &v : sub) {
                            v.insert(lower_bound(v.begin(), v.end(), candidate), candidate);
                            if (find(dp[i].begin(), dp[i].end(), v) == dp[i].end()) {
                                dp[i].push_back(v);
                            }
                        }
                    }
                }
            }
        }
        return dp[target];
    }
};