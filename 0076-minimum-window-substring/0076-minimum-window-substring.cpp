class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> targetChars(128, 0); // Store frequency of characters in t
        
        for (char c : t) {
            targetChars[c]++;
        }
        
        int requiredChars = t.size(); // Number of unique characters in t
        
        int left = 0, right = 0; // Sliding window pointers
        int minLen = INT_MAX; // Minimum window length
        int minStart = 0; // Start index of the minimum window
        
        int formed = 0; // Number of unique characters formed in the current window
        vector<int> windowChars(128, 0); // Store frequency of characters in the current window
        
        while (right < s.size()) {
            char c = s[right];
            windowChars[c]++;
            if (windowChars[c] <= targetChars[c]) {
                formed++;
            }
            
            while (formed == requiredChars && left <= right) {
                // Update the minimum window length and start index
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                
                char leftChar = s[left];
                windowChars[leftChar]--;
                if (windowChars[leftChar] < targetChars[leftChar]) {
                    formed--;
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
