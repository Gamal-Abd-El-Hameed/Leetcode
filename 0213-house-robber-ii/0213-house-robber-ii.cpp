class Solution {
private:
    int helper(vector<int>& nums, int start, int end) {        
        int notTaken = 0, taken = 0, tmp = 0;
        for (int i = start; i < end; i++) {
            tmp = max(notTaken, taken + nums[i]);
            taken = notTaken;
            notTaken = tmp;
        }
        return tmp;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];        
        return max(helper(nums, 0, n - 1), helper(nums, 1, n));
    }
};