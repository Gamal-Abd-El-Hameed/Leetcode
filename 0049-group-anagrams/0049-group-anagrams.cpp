class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (const auto & str : strs) {
            m[getKey(str)].push_back(str);
        }

        vector<vector<string>> result;
        for (auto & it : m) {
            result.push_back(it.second);
        }
        return result;
    }
private:
    string getKey(const string& str) {
        vector<int> count(26);
        for (char j : str) {
            count[j - 'a']++;
        }

        string key = "";
        for (int i : count) {
            key.append(to_string(i) + '#');
        }
        return key;
    }
};