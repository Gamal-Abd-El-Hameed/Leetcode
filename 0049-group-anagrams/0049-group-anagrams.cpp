class Solution {
private:
    bool doTwoStringsHaveSameChars(const vector<string> &strs, const vector<vector<int>> &frequencies,
                                   int firstStringIndex, int secondStringIndex) {
        const string &str1 = strs[firstStringIndex], &str2 = strs[secondStringIndex];
        if (str1.length() != str2.length())
            return false;
        return all_of(str1.begin(), str1.end(), [&](char c) {
            return frequencies[firstStringIndex][c - 'a'] == frequencies[secondStringIndex][c - 'a'];
        });
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty())
            return {};
        int numberOfStrings = strs.size();
        vector<vector<int>> frequencies(numberOfStrings, vector<int>(26, 0));
        string str;
        for (int i = 0; i < numberOfStrings; i++) {
            str = strs[i];
            for (char c: str) {
                frequencies[i][c - 'a']++;
            }
        }
        unordered_set<int> groupingSet;
        unordered_map<int, vector<string>> groupingMap;
        bool newGroup;
        for (int currentStringIndex = 0; currentStringIndex < numberOfStrings; currentStringIndex++) {
            newGroup = true;
            for (const int stringIndexInSet:groupingSet) {
                if (doTwoStringsHaveSameChars(strs, frequencies, currentStringIndex, stringIndexInSet)) {
                    groupingMap[stringIndexInSet].push_back(strs[currentStringIndex]);
                    newGroup = false;
                    break;
                }
            }
            if (newGroup) {
                groupingSet.insert(currentStringIndex);
                groupingMap[currentStringIndex].push_back(strs[currentStringIndex]);
            }
        }
        vector<vector<string>> groupsRes;
        for (const auto &pair:groupingMap) {
            groupsRes.push_back(pair.second);
        }
        return groupsRes;
    }
};