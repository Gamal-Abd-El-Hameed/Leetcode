class Solution {
private:
    void inorder(TreeNode* root, int &size) {
        if (!root)
            return;
        size++;
        inorder(root->left, size);
        inorder(root->right, size);
    }
public:
    int countNodes(TreeNode* root) {
        int size = 0;
        inorder(root, size);
        return size;
    }
};