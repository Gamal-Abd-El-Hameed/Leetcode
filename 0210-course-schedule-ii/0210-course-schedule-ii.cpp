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

        vector<int> schedule(numCourses);
        for (int scheduleCounter = 0; scheduleCounter < numCourses; scheduleCounter++) {
            bool found = false;
            for (int course = 0; course < numCourses; course++) {
                auto &coursePrerequisites = outEdges[course];
                if (coursePrerequisites == 0) {
                    schedule[scheduleCounter] = course;
                    for (auto const &neighbor:prerequisiteToCourses[course])
                        outEdges[neighbor]--;
                    coursePrerequisites = -1;
                    found = true;
                    break;
                }
            }
            if (!found)
                return {};
        }
        return schedule;
    }
};