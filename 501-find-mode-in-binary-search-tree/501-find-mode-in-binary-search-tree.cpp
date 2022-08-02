class Solution {
    int maxFreq = 0, currFreq = 0, precursor = INT_MIN;
    vector<int> ans;
    void inorder(TreeNode* root) {
        if(root == NULL)
            return;
        inorder(root->left);
        if(precursor == root->val) ++currFreq;
        else currFreq = 1;
        if(currFreq > maxFreq) {
            maxFreq = currFreq;
            ans.clear();
            ans.push_back(root->val);
        }
        else if(currFreq == maxFreq)
            ans.push_back(root->val);
        precursor = root->val;
        inorder(root->right);
    }
    public: vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};