class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0, totalGas = 0, currentGas = 0;
        for (int station = 0; station < gas.size(); station++) {
            totalGas += gas[station] - cost[station];
            currentGas += gas[station] - cost[station];
            if (currentGas < 0) {
                currentGas = 0;
                ans = station + 1;
            }
        }
        return totalGas >= 0 ? ans : -1;
    }
};