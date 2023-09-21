class Solution {
public:
    string reverseWords(const string& s) {
        stringstream ss(s);
        string word, result;
        while (ss >> word) {
            result = word + " " + result;
        }

        if (!result.empty()) {
            result.pop_back();
        }

        return result;
    }
};