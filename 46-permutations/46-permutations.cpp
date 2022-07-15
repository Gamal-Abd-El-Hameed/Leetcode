class Solution {
public:    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> taken(nums.size(), false);
        vector<int> prefix;
        return perm(nums, taken, prefix);
    }
private:
    vector<vector<int>> perm(vector<int> nums, vector<bool> taken, vector<int> prefix) {
        vector<vector<int>> res;
        if(nums.size() == prefix.size())
            res.push_back(prefix);
        for(int i = 0; i < nums.size(); i++) {
            if(!taken[i]) {
                prefix.push_back(nums[i]);
                taken[i] = true;
                vector<vector<int>> tmp = perm(nums, taken, prefix);
                for(int i = 0; i < tmp.size(); i++)
                    res.push_back(tmp[i]);
                taken[i] = false;
                prefix.pop_back();
            }                        
        }
        return res;
    }
};