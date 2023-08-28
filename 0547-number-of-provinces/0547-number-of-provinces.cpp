class Solution {
private:
    void dfs(int prev, int curr, unordered_set<int>& visited, unordered_map<int, unordered_set<int>>& G) {
        if (visited.find(curr) != visited.end())
            return;
        visited.insert(curr);
        for (int neighbor : G[curr])
            if (neighbor != prev)
                dfs(curr, neighbor, visited, G);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_set<int> visited;
        unordered_map<int, unordered_set<int>> G;
        int n = isConnected.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    G[i].insert(j);
                    G[j].insert(i);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (visited.find(i) == visited.end()) {
                ans++;
                dfs(-1, i, visited, G);
            }
        }
        return ans;
    }
};