class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxFreqElem = 0, maxFreqCount = 0;
        for (int num:nums) {
            m[num]++;
            if (m[num] > maxFreqCount) {
                maxFreqCount = m[num];
                maxFreqElem = num;
            }
        }
        return maxFreqElem;
    }
};