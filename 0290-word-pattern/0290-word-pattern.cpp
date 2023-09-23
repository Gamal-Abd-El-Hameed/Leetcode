class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> char2word;
        unordered_map<string, char> word2char;
        istringstream iss(s);
        string word;
        int i = 0;
        while (iss >> word) {
            char c = pattern[i];
            if (char2word.find(c) == char2word.end() && word2char.find(word) == word2char.end()) {
                char2word[c] = word;
                word2char[word] = c;
            }
            else if (char2word[c] != word)
                return false;
            i++;
        }
        return i == pattern.size();
    }
};