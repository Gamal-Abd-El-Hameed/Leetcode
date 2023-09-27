class BSTIterator {
private:
    vector<int> v;
    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->right);
        v.push_back(root->val);
        inorder(root->left);
    }
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }

    int next() {
        int val = v.back();
        v.pop_back();
        return val;
    }

    bool hasNext() {
        return !v.empty();
    }
};