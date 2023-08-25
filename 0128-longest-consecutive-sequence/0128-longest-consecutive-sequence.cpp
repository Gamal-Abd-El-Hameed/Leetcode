class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for (int num:nums)
            s.insert(num);
        int length = 0, maxLength = 0, element = *(s.begin());
        while (!s.empty()) {
            length++;
            maxLength = max(length, maxLength);
            s.erase(element);
            element++;
            if (s.find(element) == s.end()) {
                length = 0;
                element = *(s.begin());
            }
        }
        return maxLength;
    }
};