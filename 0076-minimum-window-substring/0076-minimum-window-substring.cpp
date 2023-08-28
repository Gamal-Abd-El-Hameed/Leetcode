class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";
        int wordLen = t.size(), sentenceLen = s.size();
        unordered_map<char, int> originalWordMap;
        unordered_set<char> wordSet;
        for (char c:t) {
            originalWordMap[c]++;
            wordSet.insert(c);
        }
        unordered_map<char, int> wordMap(originalWordMap);
        string currentWindow, minWindow = s;
        int i = 0, counter = 0;
        char c;
        int start;
        while (i < sentenceLen) {
            c = s[i];
            if (wordSet.find(c) != wordSet.end()) {
                start = i;
                currentWindow += c;
                wordMap[c]--;
                counter++;
                i++;
                break;
            }
            i++;
        }
        while (counter < wordLen && i < sentenceLen) {
            c = s[i];
            currentWindow += c;
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
                if (currentWindow.size() < minWindow.size())
                    minWindow = currentWindow;
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
                currentWindow = currentWindow.substr(start - oldStart);
            }
            else {
                end++;
                if (end == sentenceLen)
                    break;
                c = s[end];
                currentWindow += c;
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