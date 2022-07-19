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
    vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == NULL)
        return {};
    queue<TreeNode* > q;
    q.push(root);
    q.push(nullptr);
    vector<int> tempVector;
    vector<vector<int>> res;
    while(!q.empty()) {
        TreeNode* tempNode = q.front();
        tempVector.push_back(tempNode->val);
        q.pop();
        if(tempNode->left != NULL)
            q.push(tempNode->left);
        if(tempNode->right != NULL)
            q.push(tempNode->right);
        if(q.front() == nullptr) {
            res.push_back(tempVector);
            tempVector.clear();
            q.pop();
            if(!q.empty())
                q.push(nullptr);
        }
    }
    return res;
}
};