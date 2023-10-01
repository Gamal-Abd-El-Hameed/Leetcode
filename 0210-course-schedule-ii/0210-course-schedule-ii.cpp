class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> outEdges(numCourses, 0);
        unordered_map<int, vector<int>> prerequisiteToCourses;
        for (auto const &item:prerequisites) {
            auto const &course = item[0];
            auto const &prerequisite = item[1];
            outEdges[course]++;
            prerequisiteToCourses[prerequisite].push_back(course);
        }

        vector<int> schedule;
        queue<int> q;
        for (int course = 0; course < numCourses; course++)
            if (outEdges[course] == 0)
                q.push(course);
        while (!q.empty()) {
            int course = q.front(); q.pop();
            schedule.push_back(course);
            for (auto const &neighbor: prerequisiteToCourses[course])
                if (--outEdges[neighbor] == 0)
                    q.push(neighbor);
        }
        if (schedule.size() == numCourses)
            return schedule;
        return {};
    }
};