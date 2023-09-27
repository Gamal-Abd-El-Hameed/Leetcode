class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (root == p || root == q)
            return root;
        auto* leftLCA = lowestCommonAncestor(root->left, p, q);
        auto* rightLCA = lowestCommonAncestor(root->right, p, q);
        if (leftLCA && rightLCA)
            return root;
        return leftLCA ? leftLCA : rightLCA;
    }
};