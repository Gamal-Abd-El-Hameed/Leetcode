class Solution {
public:
    int ladderLength(const string& beginWord, const string& endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0)
            return 0;
        queue<string> q;
        q.push(beginWord);
        int ladderLength = 1;
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                string currWord = q.front(); q.pop();
                if (currWord == endWord) {
                    return ladderLength;
                }
                for (char &currChar:currWord) {
                    char originalChar = currChar;
                    for (char c = 'a'; c <= 'z'; c++) {
                        currChar = c;
                        if (wordSet.count(currWord)) {
                            wordSet.erase(currWord);
                            q.push(currWord);
                        }
                    }
                    currChar = originalChar;
                }
            }

            ladderLength++;
        }
        return 0;
    }
};