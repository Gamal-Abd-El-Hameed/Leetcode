class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0, index = 0;
        bool found = false;
        inorder(root, k, ans, index, found);
        return ans;
    }
private:
    void inorder(TreeNode* root, int k, int &ans, int &index, bool &found) {
        if (!root || found)
            return;
        inorder(root->left, k, ans, index, found);
        index++;
        if (index == k) {
            ans = root->val;
            found = true;
            return;
        }
        inorder(root->right, k, ans, index, found);
    }
};