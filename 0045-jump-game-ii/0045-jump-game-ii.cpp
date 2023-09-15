class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), jumps = 0, farthest = 0, currEnd = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == currEnd) {
                currEnd = farthest;
                jumps++;
                if (currEnd >= n - 1)
                    break;
            }
        }
        return jumps;
    }
};