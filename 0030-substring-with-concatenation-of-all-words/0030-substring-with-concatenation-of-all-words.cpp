class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLen = words[0].length(), wordsSize = words.size(), strLen = s.length();
        vector<int> res;
        unordered_map<string, int> wordsCounter, originalWordsCounter;
        for (const string& word:words)
            originalWordsCounter[word]++;
        for (int strIter = 0; strIter <= strLen - wordsSize * wordLen; strIter++) {
            int slidingIter = strIter, wordsFound = 0;
            wordsCounter = originalWordsCounter;
            while (slidingIter + wordLen <= strLen) {
                const string currWord = s.substr(slidingIter, wordLen);
                if (wordsCounter[currWord] > 0) {
                    wordsCounter[currWord]--;
                    wordsFound++;
                    slidingIter += wordLen;
                }
                else {
                    break;
                }
            }
            if (wordsFound == wordsSize) {
                res.push_back(strIter);
            }
        }
        return res;
    }
};