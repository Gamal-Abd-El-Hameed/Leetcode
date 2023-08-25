class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        // Sort intervals based on their start times
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= mergedIntervals.back()[1]) {
                // Merge overlapping intervals
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
            } else {
                // Add non-overlapping interval to the result
                mergedIntervals.push_back(intervals[i]);
            }
        }

        return mergedIntervals;
    }
};
