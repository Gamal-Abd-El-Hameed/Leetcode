class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        // Sort intervals by their end points
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1; // Count of non-overlapping intervals
        int prevEnd = intervals[0][1]; // End point of the first interval

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= prevEnd) {
                // Non-overlapping interval found, update count and prevEnd
                ++count;
                prevEnd = intervals[i][1];
            }
        }

        // Total number of intervals minus non-overlapping intervals gives the answer
        return intervals.size() - count;
    }
};
