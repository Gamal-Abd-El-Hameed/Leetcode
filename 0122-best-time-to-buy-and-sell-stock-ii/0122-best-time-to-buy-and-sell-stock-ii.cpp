class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), profit = 0, i = 1;
        while (i < n) {
            profit += max(0, prices[i] - prices[i - 1]);
            i++;
        }
        return profit;
    }
};