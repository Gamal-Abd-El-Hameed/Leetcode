class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i <= amount; ++i) {
        for(int coin: coins) {
            int diff = i - coin;
            if(diff >= 0 and dp[diff] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[diff]);
        }
    }
    return (dp[amount] == INT_MAX) ? -1: dp[amount];
    }
};