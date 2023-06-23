class Solution {
public:
    int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), max_value = nums[n - 1];
    return max(max_value * nums[n - 2] * nums[n - 3], max_value * nums[0] * nums[1]);
}
};