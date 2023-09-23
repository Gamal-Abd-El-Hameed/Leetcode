class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int minEnd = points[0][1], arrows = 1;
        for (const auto& point:points) {
            if (point[0] <= minEnd) {
                minEnd = min(minEnd, point[1]);
            }
            else {
                minEnd = point[1];
                arrows++;
            }
        }
        return arrows;
    }
};