class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int n = nums.size(), best = nums[0],sum = best, x;
    for(int i = 1; i < n; ++i) {
        x = nums[i];
        sum = max(x, sum + x);
        best = max(best, sum);
    }
    return best;
}
};