class Solution {
private:
    bool canTwoGenesMutate(const string &gene1, const string &gene2) {
        int differences = 0;
        for (int i = 0; i < gene1.length(); i++) {
            if (gene1[i] != gene2[i]) {
                differences++;
                if (differences > 1)
                    return false;
            }
        }
        return true;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int mutations = INT_MAX;
        queue<pair<string, int>> q;
        q.emplace(startGene, 0);
        unordered_set<string> visited;
        while (!q.empty()) {
            auto [currGene, currMutations] = q.front(); q.pop();
            visited.insert(currGene);
            if (currGene == endGene) {
                mutations = min(mutations, currMutations);
            }
            for (auto const &nextGene:bank) {
                if (visited.count(nextGene) == 0 && canTwoGenesMutate(currGene, nextGene)) {
                    q.emplace(nextGene, 1 + currMutations);
                }
            }
        }
        return mutations == INT_MAX ? -1 : mutations;
    }
};