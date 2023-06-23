class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size(), temp = 1;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = temp;
        temp = temp * nums[i];
    }
    temp = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= temp;
        temp = temp * nums[i];
    }
    return ans;
}
};