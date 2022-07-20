class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z = 0, s = nums.size()-1;
        for(int i = 0; i <= s; ++i) {
            while(nums[i] == 2 && i < s)
                swap(nums[i],nums[s--]);
            while(nums[i]==0&&i>z)
                swap(nums[i],nums[z++]);
        }
    }
};