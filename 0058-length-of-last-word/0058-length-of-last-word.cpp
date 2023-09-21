class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1, lastWordLen = 0;
        while (s[i] == ' ') {i--;}
        while (i >= 0 && s[i] != ' ') {
            i--;
            lastWordLen++;
        }
        return lastWordLen;
    }
};