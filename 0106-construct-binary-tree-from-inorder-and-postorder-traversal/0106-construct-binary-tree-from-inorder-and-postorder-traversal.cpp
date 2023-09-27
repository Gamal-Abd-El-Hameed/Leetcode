class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        int postorderIndex = postorder.size() - 1;
        return buildTreeHelper(inorder, postorder, inorderMap, postorderIndex, 0, inorder.size() - 1);
    }
private:
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int> &inorderMap,
                              int &postorderIndex, int inorderStart, int inorderEnd) {
        if (inorderStart > inorderEnd)
            return nullptr;
        auto root = new TreeNode(postorder[postorderIndex]);
        int rootIndex = inorderMap[postorder[postorderIndex]];
        postorderIndex--;
        root->right = buildTreeHelper(inorder, postorder, inorderMap, postorderIndex, rootIndex + 1, inorderEnd);
        root->left = buildTreeHelper(inorder, postorder, inorderMap, postorderIndex, inorderStart, rootIndex - 1);
        return root;
    }
};