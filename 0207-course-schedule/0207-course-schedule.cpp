class Solution {
private:
    unordered_map<int, unordered_set<int>> valuesMap;
    unordered_set<int> visited;
    bool dfs(int key) {
        if (visited.find(key) != visited.end()) return false;
        if (valuesMap[key].empty()) return true;
        visited.insert(key);
        for (int neighbor:valuesMap[key])
            if (!dfs(neighbor)) return false;
        visited.erase(key);
        valuesMap[key].clear();
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (vector<int> pair:prerequisites)
            valuesMap[pair[0]].emplace(pair[1]);
        return all_of(valuesMap.begin(), valuesMap.end(),
                                        [this](const auto &pair)
                                        { return dfs(pair.first); });

    }
};