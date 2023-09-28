class Solution {
private:
    int lowerBoundOf(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n - 1, mid, num;
        while (low <= high) {
            mid = (low + high) >> 1;
            num = nums[mid];
            if (num == target) {
                if (mid == 0 || nums[mid - 1] != num)
                    return mid;
                high = mid;
            }
            else if (num > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
    int upperBoundOf(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n - 1, mid, num;
        while (low <= high) {
            mid = (low + high) >> 1;
            num = nums[mid];
            if (num == target) {
                if (mid == n - 1 || nums[mid + 1] != num)
                    return mid;
                low = mid;
            }
            if (num > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lowerBound = lowerBoundOf(nums, target);
        if (lowerBound == -1)
            return {-1, -1};
        int upperBound = upperBoundOf(nums, target);
        return {lowerBound, upperBound};
    }
};