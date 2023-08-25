class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        // sort on end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int removedIntervals = 0;
        vector<int> currentInterval, lastInterval;
        lastInterval = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            currentInterval = intervals[i];
            if (currentInterval[0] < lastInterval[1]) {
                removedIntervals++;
            }
            else
                lastInterval = currentInterval;
        }
        return removedIntervals;
    }
};