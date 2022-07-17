class Solution {
public:
    vector<vector<int>> ans;
void helper(int n, int index, int k, vector<int> output) {
    output.push_back(index + 1);
    if(k == 1) // index == n + 1
        return ans.push_back(output);
    for(int i = index + 1; i < n; ++i) {
        helper(n, i, k - 1, output);
    }
}
vector<vector<int>> combine(int n, int k) {
    for(int i = 0; i <= n - k; ++i)
        helper(n, i, k, {});
    return ans;
}
};
