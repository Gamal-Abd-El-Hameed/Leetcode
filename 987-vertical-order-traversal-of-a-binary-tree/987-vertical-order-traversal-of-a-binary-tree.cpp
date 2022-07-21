/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    queue<pair<pair<int, int>, TreeNode*>> q;
    vector<vector<int>> res;
    map<int, vector<pair<int, int>>> indexToVectorMap;
    q.push({{0, 0}, root});
    while(!q.empty()) {
        pair<pair<int, int>, TreeNode*> front = q.front();
        q.pop();
        int row = front.first.first, col = front.first.second;
        TreeNode* node = front.second;
        indexToVectorMap[col].push_back({row, node->val});
        if(node->left)
            q.push({{row + 1, col - 1}, node->left});
        if(node->right)
            q.push({{row + 1, col + 1}, node->right});
    }
    vector<pair<int, int>> v;
    vector<int> t;
    for(auto m : indexToVectorMap) {
        v = m.second;
        sort(v.begin(), v.end());
        t.clear();
        for(auto p : v)
            t.push_back(p.second);
        res.push_back(t);
    }
    return res;
}
};