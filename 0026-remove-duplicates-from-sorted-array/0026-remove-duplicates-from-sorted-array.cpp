class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0, i = 1, n = nums.size();
        while (i < n) {
            if (nums[i] != nums[start])
                nums[++start] = nums[i];
            i++;
        }
        return start + 1;
    }
};