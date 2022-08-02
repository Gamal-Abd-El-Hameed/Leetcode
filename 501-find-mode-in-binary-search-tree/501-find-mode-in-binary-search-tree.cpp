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
unordered_map<int, int> m;
void inorder(TreeNode* root) {
    if(root == NULL)
        return;
    inorder(root->left);
    int val = root->val;
    if(m.count(val))
        ++m[val];
    else
        m.insert({val, 1});
    inorder(root->right);
}

public:vector<int> findMode(TreeNode* root) {
    if(root == NULL)
        return {};
    vector<int> ans;
    inorder(root);
    int maxElem = 0;
    for(auto n : m)
        maxElem = max(maxElem, n.second);
    for(auto n: m)
        if(n.second == maxElem)
            ans.push_back(n.first);
    return ans;
}
};