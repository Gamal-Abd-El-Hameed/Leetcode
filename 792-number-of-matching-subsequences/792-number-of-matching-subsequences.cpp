class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
    unordered_map<string, int> wordsMap;
    for(string word: words)
        ++wordsMap[word];
    unordered_map<char, int> sMap, wMap;
    for(char ch: s)
        ++sMap[ch];
    int ans = 0, n = s.length(), m, i, j;
    bool isSubset;
    string word;
    for(auto wordMap : wordsMap) {
        word = wordMap.first;
        wMap.clear();
        isSubset = true;
        for(char ch : word)
            ++wMap[ch];
        for(auto m : wMap)
            if(m.second > sMap[m.first]) {
                isSubset = false;
                break;
            }
        if(!isSubset)
            continue;
        i = 0, j = 0, m = word.length();
        while(i < n && j < m) {
            if(s[i] == word[j]) ++j;
            ++i;
        }
        if(j == m)
            ans += wordMap.second;
    }
    return ans;
}
};