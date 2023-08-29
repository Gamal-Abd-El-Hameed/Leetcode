class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charFreq;

        for (char c : t) {
            charFreq[c]++;
        }

        int requiredChars = t.size(), left = 0, right = 0, minLen = INT_MAX, minStart = 0, formed = 0;
        char c, leftChar;
        while (right < s.size()) {
            c = s[right];
            if (charFreq.count(c)) {
                if (charFreq[c] > 0) {
                    formed++;
                }
                charFreq[c]--;
            }

            while (formed == requiredChars && left <= right) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                leftChar = s[left];
                if (charFreq.count(leftChar)) {
                    if (charFreq[leftChar] >= 0) {
                        formed--;
                    }
                    charFreq[leftChar]++;
                }

                left++;
            }

            right++;
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(minStart, minLen);
    }
};