class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), end = n - 1, i = end - 1, k;
        if (n == 1)
            return 1;
        while (i >= 0) {
            if (nums[i] == nums[i + 1]) {
                k = i + 1;
                while (k <= end - 1) {
                    nums[k] = nums[k + 1];
                    k++;
                }
                end--;
            }
            i--;
        }
        return end + 1;
    }
};