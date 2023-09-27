class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int leftHeight = 0, rightHeight = 0;
        TreeNode *leftNode = root, *rightNode = root;
        while (leftNode) {
            leftHeight++;
            leftNode = leftNode->left;
        }
        while (rightNode) {
            rightHeight++;
            rightNode = rightNode->right;
        }
        if (leftHeight == rightHeight)
            return (1 << leftHeight) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};