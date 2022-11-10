class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int coin: coins)
            if(coin <= amount)
                dp[coin] = 1;
        int diff;
        for(int i = 1; i <= amount; ++i) {
            for(int coin: coins) {
                diff = i - coin;
                if(diff >= 0 && dp[diff] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[diff]);
            }
        }
        return (dp[amount] == INT_MAX) ? -1: dp[amount];
    }
};