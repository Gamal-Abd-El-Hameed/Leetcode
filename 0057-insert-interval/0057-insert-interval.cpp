class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool isInserted = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] >= newInterval[0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                isInserted = true;
                break;
            }
        }
        if (!isInserted)
            intervals.push_back(newInterval);
        int i = 1;
        while (i < intervals.size()) {
            if (intervals[i - 1][0] <= intervals[i][0]
            &&  intervals[i][0] <= intervals[i - 1][1]
            &&  intervals[i - 1][1] <= intervals[i][1]) {
                intervals[i - 1][1] = intervals[i][1];
                intervals.erase(intervals.begin() + i);
            }
            else if (intervals[i][0] >= intervals[i - 1][0]
            &&       intervals[i][1] <= intervals[i - 1][1]) {
                intervals.erase(intervals.begin() + i);
            }
            else i++;
        }
        return intervals;
    }
};