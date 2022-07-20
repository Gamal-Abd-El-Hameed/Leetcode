/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> res;
void print(TreeNode* root, int k) {
    if(root == NULL)
        return;
    if(k == 0)
        return res.push_back(root->val);
    if(root->left)
        print(root->left, k - 1);
    if(root->right)
        print(root->right, k - 1);
}
int findK(TreeNode* root, TreeNode* target, int k) {
    if(root == NULL)
        return -1;
    if(root == target)
        return print(target, k), 0;
    int D = findK(root->left, target, k);
    if(D != -1) {
        if(D + 1 == k)
            res.push_back(root->val);
        else
            print(root->right, k - 2 - D);
        return 1 + D;
    }
    D = findK(root->right, target, k);
    if(D != -1) {
        if(D + 1 == k)
            res.push_back(root->val);
        else
            print(root->left, k - 2 - D);
        return 1 + D;
    }
    return -1;
}
public:
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    findK(root, target, k);
    return res;
}
};