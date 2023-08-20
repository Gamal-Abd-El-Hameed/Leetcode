class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n - 1, current = n - 2;
        while (current >= 0) {
            if (nums[current] + current >= goal) goal = current;
            current--;
        }
        return goal == 0;
    }
};