/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL)
        return NULL;
    if(root->val > key)
        root->left = deleteNode(root->left, key);
    else if(root->val < key)
        root->right = deleteNode(root->right, key);
    else {
        if(root->right == NULL && root->left == NULL)
            root = NULL;        
        else if(root->right == NULL) {
            TreeNode* temp = root;
            root = root->left;
            delete temp;
        }
        else if(root->left == NULL) {
            TreeNode* temp = root;
            root = root->right;
            delete temp;
        }
        else {
            TreeNode* leftMostNode = root->right;
            while(leftMostNode->left)
                leftMostNode = leftMostNode->left;
            root->val = leftMostNode->val;
            root->right = deleteNode(root->right, leftMostNode->val);
        }
    }
    return root;
}
};