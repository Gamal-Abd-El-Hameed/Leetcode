class Solution {
public:
    bool search(vector<int>& nums, int target) {
    int n = nums.size();
    if(n == 0) return false;
    int start = 0, end = n - 1, mid, pivot, firstElement;
    while(start <= end) {
        firstElement = nums[start];
        mid = (start + end) >> 1;
        pivot = nums[mid];
        if(pivot == target) return true;
        if(pivot == firstElement) {
            ++start;
            continue;
        }
        bool pivotArray = (firstElement <= pivot);
        bool targetArray = (firstElement <= target);
        if(pivotArray ^ targetArray) {
            if(pivotArray)
                start = mid + 1;
            else
                end = mid - 1;
        }
        else {
            if(pivot < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return false;
}
};