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
    int maxDepth(TreeNode* root) {
    if (root == nullptr)
        return 0;
    int level = 0, size;
    deque<TreeNode*> Q;
    Q.push_back(root);
    while (!Q.empty()) {
        size = Q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *temp = Q.front();
            Q.pop_front();
            if (temp->left)
                Q.push_back(temp->left);
            if (temp->right)
                Q.push_back(temp->right);
        }
        level++;
    }
    return level;
}
};