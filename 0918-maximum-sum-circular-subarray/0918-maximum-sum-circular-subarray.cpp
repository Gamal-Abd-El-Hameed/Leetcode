class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0, globMaxSum = INT_MIN, globMinSum = INT_MAX, currMaxSum = 0, currMinSum = 0;
        for (int num:nums) {
            totalSum += num;
            currMaxSum = max(currMaxSum + num, num);
            globMaxSum = max(globMaxSum, currMaxSum);
            currMinSum = min(currMinSum + num, num);
            globMinSum = min(globMinSum, currMinSum);
        }
        if (globMaxSum < 0)
            return globMaxSum;
        return max(globMaxSum, totalSum - globMinSum);
    }
};