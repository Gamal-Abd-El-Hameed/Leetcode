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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        queue<TreeNode*> Q;
        TreeNode* head;
        TreeNode* left;
        TreeNode* right;
        Q.push(root);
        while (!Q.empty()) {
            head = Q.front();
            Q.pop();
            left = head->left;
            right = head->right;
            head->left = right;
            head->right = left;
            if (left)
                Q.push(left);
            if (right)
                Q.push(right);
        }
        return root;
    }
};