class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, x;
        deque<int> d;
        while(i < k) {
            x = nums[i];
            while(!d.empty() and x >= nums[d.back()])
                d.pop_back();
            d.push_back(i);
            ++i;
        }
        vector<int> ans;
        while(i < n) {
            ans.push_back(nums[d.front()]);
            x = nums[i];
            while(!d.empty() and d.front() <= i - k)
                d.pop_front();
            while(!d.empty() and x >= nums[d.back()])
                d.pop_back();
            d.push_back(i);
            ++i;
        }
        ans.push_back(nums[d.front()]);
        return ans;
    }
};