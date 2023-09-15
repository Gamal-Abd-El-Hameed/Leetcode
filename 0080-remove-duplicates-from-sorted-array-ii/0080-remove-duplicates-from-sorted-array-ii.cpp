class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 2, i = 2, n = nums.size();
        if (n <= 2) return n;
        while (i < n) {
            if (nums[i] != nums[start - 2])
                nums[start++] = nums[i];
            i++;
        }
        return start;
    }
};