class Solution {
private:
    int subStringStart = 0, maxLen = 0;

    void expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        int len = right - left - 1;
        if (len > maxLen) {
            maxLen = len;
            subStringStart = left + 1;
        }
    }

public:
    string longestPalindrome(string s) {
        int n = s.length();

        for (int i = 0; i < n; i++) {
            expandAroundCenter(s, i, i);       // Odd length palindrome
            expandAroundCenter(s, i, i + 1);   // Even length palindrome
        }

        return s.substr(subStringStart, maxLen);
    }
};