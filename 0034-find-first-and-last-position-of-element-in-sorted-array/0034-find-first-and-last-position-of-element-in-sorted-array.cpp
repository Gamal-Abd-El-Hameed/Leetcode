class Solution {
private:
    int getLowerBound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1, mid, num;
        while (low <= high) {
            mid = (low + high) >> 1;
            num = nums[mid];
            if (num >= target) {
                high = mid - 1;
                if (num == target)
                    ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int getUpperBound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1, mid, num;
        while (low <= high) {
            mid = (low + high) >> 1;
            num = nums[mid];
            if (num <= target) {
                low = mid + 1;
                if (num == target)
                    ans = mid;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lowerBound = getLowerBound(nums, target);
        if (lowerBound == -1)
            return {-1, -1};
        int upperBound = getUpperBound(nums, target);
        return {lowerBound, upperBound};
    }
};