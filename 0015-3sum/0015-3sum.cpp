class Solution {    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size(), low, high, sum;
        for(int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            low = i + 1, high = n - 1;
            while (low < high) {
                sum = nums[i] + nums[low] + nums[high];
                if (sum == 0) {
                    res.push_back({nums[i], nums[low], nums[high]});
                    low++;                
                    while (low < high && nums[low] == nums[low - 1])
                        low++;
                }
                if (sum < 0) low++;
                else high--;
            }
        }
        return res;
    }
};