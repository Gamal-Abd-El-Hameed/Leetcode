class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        int i = 0, n = nums.size();
        while (i <= k && i < n) {
            if (++numCount[nums[i++]] == 2)
                return true;
        }
        int start = 0, end = i;
        while (end < n){
            --numCount[nums[start++]];
            if (++numCount[nums[end++]] == 2)
                return true;
        }
        return false;
    }
};