class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set < int >s;
        for (int price : nums) {
        if (s.find(price) != s.end()) {
            return true;
        }
        s.insert(price);
        }
            return false;
    }
};