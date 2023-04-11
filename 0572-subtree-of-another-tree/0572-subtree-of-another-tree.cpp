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
    bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p || !q)
        return p == q;
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root)
        return !subRoot;
    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty()) {
        root = Q.front();
        Q.pop();
        if (isSameTree(root, subRoot))
            return true;
        if (root->left)
            Q.push(root->left);
        if (root->right)
            Q.push(root->right);
    }
    return false;
}
};