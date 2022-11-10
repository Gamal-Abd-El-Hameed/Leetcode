public class Solution {

  public int coinChange(int[] coins, int amount) {
    return coinChange(coins, amount, new int[amount + 1]);
  }

  private int coinChange(int[] coins, int amount, int[] dp) {
    if (amount == 0) {
        dp[0] = 0;
        return 0;
    }
    if (dp[amount] != 0) return dp[amount];
    int min = Integer.MAX_VALUE;
    int diff;
    for (int coin : coins) {
        diff = amount - coin;
        if (diff < 0)
            continue;
      int res = coinChange(coins, diff, dp);
      if (res >= 0 && res < min)
        min = 1 + res;
    }
    dp[amount] = (min == Integer.MAX_VALUE) ? -1 : min;
    return dp[amount];
  }
}