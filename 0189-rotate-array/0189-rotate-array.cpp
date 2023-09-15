class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (n <= 1 || k == 0)
            return;
        int i = 1, shift = n - k, tempElem = nums[shift];
        vector<int> tempNums = nums;
        while (i < n) {
            nums[i] = tempNums[(i + shift) % n];
            i++;
        }
        nums[0] = tempElem;
    }
};