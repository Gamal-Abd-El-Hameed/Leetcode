class Solution {
public:
    int maximumProduct(vector<int>& nums) {
    int n = nums.size(), max_value, second_max_value, third_max_value, min_value, second_min_value;
    max_value = second_max_value = third_max_value = INT_MIN;
    min_value = second_min_value = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (nums[i] > max_value) {
            third_max_value = second_max_value;
            second_max_value = max_value;
            max_value = nums[i];
        } else if (nums[i] > second_max_value) {
            third_max_value = second_max_value;
            second_max_value = nums[i];
        } else if (nums[i] > third_max_value) {
            third_max_value = nums[i];
        }
        if (nums[i] < min_value) {
            second_min_value = min_value;
            min_value = nums[i];
        } else if (nums[i] < second_min_value) {
            second_min_value = nums[i];
        }
    }
    return max(max_value * second_max_value * third_max_value, max_value * min_value * second_min_value);
}
};