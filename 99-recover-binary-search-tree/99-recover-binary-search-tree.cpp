class Solution {
    TreeNode* first;
    TreeNode* second;
    TreeNode* pre;
    void inorder(TreeNode* root) {
        if(root==NULL) return;
        inorder(root->left);
        
        if(first==NULL && (pre==NULL ||pre->val>=root->val))
            first = pre;        
        if(first!=NULL && pre->val>=root->val)
            second = root;        
        pre = root;
        inorder(root->right);
    }
    public:void recoverTree(TreeNode* root) {
        if(root==NULL) return;
        first = NULL;
        second = NULL;
        pre = NULL;
        inorder(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }    
};