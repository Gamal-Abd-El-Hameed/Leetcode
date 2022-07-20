class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colors[3] = {0,0,0};
        for(int x: nums)
            ++colors[x];
        int i = 0, c = 0;
        for(int x: colors) {
            while(x--) {
                nums[i] = c;
                ++i;
            }
            ++c;
        }
    }
};