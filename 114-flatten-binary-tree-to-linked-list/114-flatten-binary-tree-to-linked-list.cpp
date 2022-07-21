class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode* t;
        while(root) {
            if(root->left && root->right) {
                t = root->left;
                while(t->right)
                    t = t->right;
                t->right = root->right;
            }
            if(root->left)
                root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
};