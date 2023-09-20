class Solution {
public:
    int trap(vector<int>& height) {
        int totalWater = 0, start = 0, end = 0, n = height.size(), maxHeight;
        while (end < n) {
            if (height[start] <= height[end]) {
                maxHeight = min(height[start], height[end]);
                for (int trap = start + 1; trap < end; trap++)
                    totalWater += maxHeight - height[trap];
                start = end;
            }
            end++;
        }
        start = n - 1, end = n - 1;
        while (start >= 0) {
            if (height[start] > height[end]) {
                maxHeight = min(height[start], height[end]);
                for (int trap = end - 1; trap > start; trap--)
                    totalWater += maxHeight - height[trap];
                end = start;
            }
            start--;
        }
        return totalWater;
    }
};