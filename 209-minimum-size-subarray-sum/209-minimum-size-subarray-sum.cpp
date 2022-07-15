class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    int i = 0, j = 0, n = nums.size();
    int sum = 0, best = INT_MAX;
    while(j < n) {
        sum += nums[j];
        ++j;
        while (sum >= target) {
            best = min(best, j - i);
            sum -= nums[i];
            ++i;
        }
    }
    return (best == INT_MAX) ? 0: best;
}
};