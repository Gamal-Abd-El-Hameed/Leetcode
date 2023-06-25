class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int mid, ans = nums[0];
        while (low <= high) {
            if (nums[low] < nums[high])
                return min(ans, nums[low]);
            mid = (low + high) >> 1;
            ans = min(ans, nums[mid]);
            if (nums[mid] >= nums[low])
                low = mid + 1;
            else
                high = mid - 1;                        
        }
        return ans;
    }
};