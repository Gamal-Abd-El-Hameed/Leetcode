class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int min_value = 1, max_value = 1, res = INT_MIN, tmp;
    for (int num : nums) {
        tmp = max_value;
        max_value = max(num, max(num * max_value, num * min_value));
        min_value = min(num, min(num * tmp, num * min_value));
        res = max(res, max(max_value, min_value));
    }
    return res;
}
};