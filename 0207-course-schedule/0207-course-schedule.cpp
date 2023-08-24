class Solution {
private:
    unordered_set<int> done;
    unordered_map<int, unordered_set<int>> valuesMap;
    unordered_set<int> visited;
    bool dfs(int key) {
        if (done.find(key) != done.end()) return true;
        visited.insert(key);
        for (int neighbor:valuesMap[key]) {
            if (valuesMap.find(neighbor) == valuesMap.end()) continue;
            if (visited.find(neighbor) != visited.end()) return false;
            if (!dfs(neighbor)) return false;
        }
        visited.erase(key);
        done.insert(key);
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        valuesMap.reserve(numCourses);
        for (vector<int> pair:prerequisites)
            valuesMap[pair[0]].emplace(pair[1]);
        return all_of(valuesMap.begin(), valuesMap.end(),
                                        [this](const auto &pair)
                                        { return dfs(pair.first); });

    }
};