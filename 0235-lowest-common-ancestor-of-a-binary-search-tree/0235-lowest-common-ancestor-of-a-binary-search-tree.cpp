class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rootVal = root->val, pVal = p->val, qVal = q->val;
        if (pVal < rootVal && qVal < rootVal)
            return lowestCommonAncestor(root->left, p, q);

        if (pVal > rootVal && qVal > rootVal)
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};