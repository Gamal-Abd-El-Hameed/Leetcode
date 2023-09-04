class Solution {
private:
    void expandAroundCenter(const string &s, int left, int right, int &ans) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            ans++;
            left--;
            right++;
        }
    }

public:
    int countSubstrings(string s) {
        int n = s.length(), ans = 0;

        for (int i = 0; i < n; i++) {
            expandAroundCenter(s, i, i, ans);
            expandAroundCenter(s, i, i + 1, ans);
        }

        return ans;
    }
};