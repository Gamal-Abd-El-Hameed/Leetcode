class Solution {
public:
    vector<vector<int>> ans;
void helper(int n, int index, int k, vector<int> output) {    
    if(k == 0)
        return ans.push_back(output);
    if(index <= n - k)
        helper(n, index + 1, k, output);
    output.push_back(index);
    helper(n, index + 1, k - 1, output);
}
vector<vector<int>> combine(int n, int k) {
    helper(n, 1, k, {});
    return ans;
}
};
