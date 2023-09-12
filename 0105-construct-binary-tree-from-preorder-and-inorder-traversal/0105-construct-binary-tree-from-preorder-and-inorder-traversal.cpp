class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        int preorderIndex = 0;
        return buildTreeHelper(preorder, inorder, inorderMap, preorderIndex, 0, inorder.size() - 1);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &inorderMap,
                              int &preorderIndex, int inorderStart, int inorderEnd) {
        if (inorderStart > inorderEnd)
            return nullptr;
        auto root = new TreeNode(preorder[preorderIndex]);
        int rootIndex = inorderMap[preorder[preorderIndex]];
        preorderIndex++;
        root->left = buildTreeHelper(preorder, inorder, inorderMap, preorderIndex, inorderStart, rootIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, inorderMap, preorderIndex, rootIndex + 1, inorderEnd);
        return root;
    }
};