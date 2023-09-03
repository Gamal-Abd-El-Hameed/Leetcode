class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (int num:nums)
            frequencyMap[num]++;
         priority_queue<pair<int, int>> q;
        for (auto &numPair:frequencyMap)
            q.emplace(numPair.second, numPair.first);
        vector<int> res;
        pair<int, int> numPair;
        while (k--) {
            numPair = q.top();
            q.pop();
            res.push_back(numPair.second);
        }
        return res;
    }
};