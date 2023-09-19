class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
            return -1;
        int ans = 0, totalGas = 0;
        for (int station = 0; station < gas.size(); station++) {
            totalGas += gas[station] - cost[station];
            if (totalGas < 0) {
                totalGas = 0;
                ans = station + 1;
            }
        }
        return ans;
    }
};