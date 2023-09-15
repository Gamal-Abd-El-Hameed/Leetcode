class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), goal = n - 1, curr, jumps = 0, newGoal;
        while (goal) {
            curr = goal - 1;
            jumps++;
            while (curr >= 0) {
                if (nums[curr] + curr >= goal) {
                    newGoal = curr;
                }
                curr--;
            }
            goal = newGoal;
        }
        return jumps;
    }
};