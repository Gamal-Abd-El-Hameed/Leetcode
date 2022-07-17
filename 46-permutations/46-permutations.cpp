class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums, 0);
        return res;
    }
private:
    void perm(vector<int>& nums, int index) {
        if(index == nums.size())
            return res.push_back(nums);
        for(int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            perm(nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
};