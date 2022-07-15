class Solution {
public:
    int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1, mid;
    while(lo <= hi) {
        mid = (lo + hi) >> 1;
        int current = nums[mid];
        if(current == target)
            return mid;
        if(nums[lo] <= current) {
            if(target < current and nums[lo] <= target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        else {
            if(current < target and target <= nums[hi])
                lo = mid + 1;
            else
                hi = mid - 1;
        }

    }
    return -1;
}
};