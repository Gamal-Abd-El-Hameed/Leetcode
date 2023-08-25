class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> currentInterval, newInterval;
        newInterval = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            currentInterval = intervals[i];
            if (currentInterval[0] <= newInterval[1]) {
                newInterval[1] = max(newInterval[1], currentInterval[1]);
                if (i == intervals.size() - 1)
                    res.push_back(newInterval);
            }
            else {
                res.push_back(newInterval);
                newInterval = currentInterval;
                if (i == intervals.size() - 1)
                    res.push_back(currentInterval);
            }
        }
        return res;
    }
};