class Solution {
private:
    void getValue(unordered_map<string, vector<pair<string, double>>> &equationsMap, unordered_set<string> &visited,
                  const string &firstOperand, const string &secondOperand, double &queryResult, bool &found) {
        if (equationsMap.find(firstOperand) == equationsMap.end()
        ||  equationsMap.find(secondOperand) == equationsMap.end()
        ||  visited.find(firstOperand) != visited.end())
            return;
        visited.insert(firstOperand);
        if (firstOperand == secondOperand) {
            found = true;
            return;
        }
        auto const& equationNeighbors = equationsMap[firstOperand];
        for (const auto& pair:equationNeighbors) {
            if (pair.first == secondOperand) {
                queryResult *= pair.second;
                found = true;
                return;
            }
        }
        for (const auto& pair:equationNeighbors) {
            queryResult *= pair.second;
            getValue(equationsMap, visited, pair.first, secondOperand, queryResult, found);
            if (found)
                break;
            queryResult /= pair.second;
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> equationsMap;
        for (int equationsCounter = 0; equationsCounter < equations.size(); equationsCounter++) {
            auto const& equation = equations[equationsCounter];
            double value = values[equationsCounter];
            equationsMap[equation[0]].emplace_back(equation[1], value);
            equationsMap[equation[1]].emplace_back(equation[0], 1.0 / value);
        }
        vector<double> res(queries.size());
        int queryCounter = 0;
        unordered_set<string> visited;
        for (auto const& query:queries) {
            double queryResult = 1.0;
            bool found = false;
            visited.clear();
            getValue(equationsMap, visited, query[0], query[1], queryResult, found);
            res[queryCounter++] = found ? queryResult : -1;
        }
        return res;
    }
};