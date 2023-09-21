class Solution {
public:
    string reverseWords(string s) {
        int i = s.length() - 1;
        string word, res;
        while (true) {
            while (i >= 0 && s[i] == ' ') i--;
            word = "";
            while (i >= 0 && s[i] != ' ') {
                word += s[i];
                i--;
            }
            if (word.empty()) {
                if (!res.empty())
                    res.pop_back();
                break;
            }
            reverse(word.begin(), word.end());
            res += word;
            res += ' ';
        }
        return res;
    }
};