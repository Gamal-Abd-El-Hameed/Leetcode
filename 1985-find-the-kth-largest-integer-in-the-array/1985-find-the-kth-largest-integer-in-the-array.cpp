class Solution {
    class Compare {
public:
    bool operator()(const string &a, const string& b) {
        if(a.size() != b.size())
            return a.size() > b.size();
        return a > b;
    }
};

bool compare (const string &a, const string& b) {
    if(a.size() != b.size())
        return a.size() > b.size();
    return a > b;
}

public:string kthLargestNumber(vector<string>& nums, int k) {
    priority_queue<string, vector<string>, Compare> heap;
    for(int i = 0; i < k; ++i)
        heap.push(nums[i]);
    for(int i = k; i < nums.size(); ++i) {
        if(compare(nums[i], heap.top())) {
            heap.pop();
            heap.push(nums[i]);
        }
    }
    return heap.top();
}
};