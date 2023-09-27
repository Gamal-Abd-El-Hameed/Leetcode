class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (root->val == p->val && findInSubTree(root, q))
            return root;
        if (root->val == q->val && findInSubTree(root, p))
            return root;
        auto leftSubTree = lowestCommonAncestor(root->left, p, q);
        if (leftSubTree)
            return leftSubTree;
        auto rightSubTree = lowestCommonAncestor(root->right, p, q);
        if (rightSubTree)
            return rightSubTree;
        if (findInSubTree(root->left, p) && findInSubTree(root->right, q))
            return root;
        if (findInSubTree(root->left, q) && findInSubTree(root->right, p))
            return root;
        return nullptr;
    }
private:
    bool findInSubTree(TreeNode* root, TreeNode* child) {
        if (!root)
            return false;
        if (root->val == child->val)
            return true;
        return findInSubTree(root->left, child) || findInSubTree(root->right, child);
    }
};