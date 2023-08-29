class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty())
            return "";
        int wordLen = t.size(), sentenceLen = s.size();
        unordered_map<char, int> wordMap;
        unordered_set<char> wordSet;
        for (char c:t) {
            wordMap[c]++;
            wordSet.insert(c);
        }
        string minWindow = s;
        int i = 0, counter = 0, start;
        char c;
        while (i < sentenceLen) {
            c = s[i];
            if (wordSet.find(c) != wordSet.end()) {
                start = i;
                wordMap[c]--;
                counter++;
                i++;
                break;
            }
            i++;
        }
        while (counter < wordLen && i < sentenceLen) {
            c = s[i];
            if (wordSet.find(c) != wordSet.end()) {
                if (wordMap[c] > 0)
                    counter++;
                wordMap[c]--;
            }
            i++;
        }
        if (counter < wordLen)
            return "";
        int end = i - 1, oldStart;
        while (end < sentenceLen) {
            if (counter == wordLen) {
                oldStart = start;
                if (end - start + 1 < minWindow.size())
                    minWindow = s.substr(start, end - start + 1);
                if (wordMap[s[start]] == 0)
                    counter--;
                wordMap[s[start]]++;
                start++;
                while (start < end) {
                    if (wordSet.find(s[start]) == wordSet.end()) {
                        start++;
                        continue;
                    }
                    else if (wordMap[s[start]] < 0) {
                        wordMap[s[start]]++;
                        start++;
                        continue;
                    }
                    else break;
                }
            }
            else {
                end++;
                if (end == sentenceLen)
                    break;
                c = s[end];
                if (wordSet.find(c) != wordSet.end()) {
                    if (wordMap[c] > 0)
                        counter++;
                    wordMap[c]--;
                }
            }
        }
        return minWindow;
    }
};