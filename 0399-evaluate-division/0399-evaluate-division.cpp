class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            auto const &equation = equations[i];
            const string &a = equation[0];
            const string &b = equation[1];
            double value = values[i];
            graph[a][b] = value;
            graph[b][a] = 1 / value;
        }
        function<double(const string&, const string&)> dfs = [&](const string& start, const string& end) {
            if (!graph.count(start) || !graph.count(end))
                return -1.0;
            if (start == end)
                return 1.0;
            unordered_set<string> visited;
            stack<pair<string, double>> s;
            s.emplace(start, 1.0);
            while (!s.empty()) {
                auto [current, currentRes] = s.top(); s.pop();
                if (current == end)
                    return currentRes;
                visited.insert(current);
                for (auto const &neighbor:graph[current]) {
                    const string &next = neighbor.first;
                    double edgeWeight = neighbor.second;
                    if (!visited.count(next))
                        s.emplace(next, edgeWeight * currentRes);
                }
            }
            return -1.0;
        };
        vector<double> res(queries.size());
        int i = 0;
        for (auto const &query:queries)
            res[i++] = dfs(query[0], query[1]);
        return res;
    }
};