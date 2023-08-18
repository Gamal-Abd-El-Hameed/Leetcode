class Solution {
public:
    int rob(vector<int>& nums) {        
        int notTaken = 0, taken = 0, tmp;
        for (int num:nums) {
            tmp = max(notTaken, taken + num);
            taken = notTaken;
            notTaken = tmp;
        }
        return tmp;
    }
};