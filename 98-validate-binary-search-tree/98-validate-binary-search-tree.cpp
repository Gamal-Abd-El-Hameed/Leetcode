class Solution {
   bool helper(TreeNode* root, TreeNode* &prev) {
    if(root == NULL)
        return true;
    if(!helper(root->left, prev))
        return false;
    if(prev != NULL && prev->val >= root->val)
        return false;
    prev = root;
    return helper(root->right, prev);
}
public:
bool isValidBST(TreeNode* root) {
    TreeNode* prev = NULL;
    return helper(root, prev);
}
};