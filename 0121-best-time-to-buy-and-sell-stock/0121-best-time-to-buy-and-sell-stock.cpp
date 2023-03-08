class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size (), profit;
        int l = 0, r = 1, maxP = 0;
        while (r < n) {
            profit = prices[r] - prices[l];
            if (profit > 0)
                maxP = max(maxP, profit);
            else l = r;
            r++;
        }
        return maxP;
    }
};