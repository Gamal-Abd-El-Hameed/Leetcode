class Solution {
private:
    bool canMakeValidSubstring(const string& s, int substringLength, int k) {
        int frequencies[26];
        fill_n(frequencies, 26, 0);
        int start = 0, maxFreq = 0, n = s.size();
        for (int end = 0; end < n; end++) {
            ++frequencies[s[end] - 'A'];
            if (end - start + 1 > substringLength) {
                frequencies[s[start] - 'A']--;
                start++;
            }
            maxFreq = max(maxFreq, frequencies[s[end] - 'A']);
            if (substringLength - maxFreq <= k) {
                return true;
            }
        }
        return false;
    }
public:
    int characterReplacement(string s, int k) {
        int lo = 1, hi = s.size() + 1, mid;
        while (lo + 1 < hi) {
            mid = lo + ((hi - lo) >> 1);
            if (canMakeValidSubstring(s, mid, k))
                lo = mid;
            else
                hi = mid;
        }
        return lo;
    }
};