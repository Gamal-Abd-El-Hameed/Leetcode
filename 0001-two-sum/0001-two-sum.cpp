class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> value_to_index_map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (value_to_index_map.find(complement) != value_to_index_map.end())
                return {i, value_to_index_map[complement]};
            value_to_index_map.insert({nums[i], i});
        }
        return {};
    }
};