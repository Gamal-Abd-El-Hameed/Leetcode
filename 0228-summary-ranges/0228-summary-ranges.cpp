class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
            return {};
        int prevNum = nums[0], leftNum = prevNum, num;
        vector<string> res;
        for (int i = 1; i < nums.size(); i++) {
            num = nums[i];
            if (num - 1 != prevNum) {
                if (prevNum == leftNum) {
                    res.push_back(to_string(leftNum));
                }
                else {
                    res.push_back(to_string(leftNum) + "->" + to_string(prevNum));
                }
                leftNum = num;
            }
            prevNum = num;
        }
        if (prevNum == leftNum) {
            res.push_back(to_string(leftNum));
        }
        else {
            res.push_back(to_string(leftNum) + "->" + to_string(prevNum));
        }
        return res;
    }
};