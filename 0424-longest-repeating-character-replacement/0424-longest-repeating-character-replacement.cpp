class Solution {
public:
    int characterReplacement(string s, int k) {
        int frequencies[26];
        fill_n(frequencies, 26, 0);
        int left = 0, maxFreq = 0, ans = 0, n = s.size();
        for (int right = 0; right < n; right++) {
            frequencies[s[right] - 'A']++;
            maxFreq = max(maxFreq, frequencies[s[right] - 'A']);
            while (right - left + 1 - maxFreq > k) {
                frequencies[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};