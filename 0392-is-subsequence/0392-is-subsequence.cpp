class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0, subLen = s.length(), strLen = t.length();
        while (i < subLen && j < strLen) {
            if (s[i] == t[j])
                i++;
            j++;
        }
        return i == subLen;
    }
};