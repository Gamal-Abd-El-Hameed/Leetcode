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
    int makeVine(TreeNode* grand) {
    int cnt = 0;
    TreeNode* n = grand->right;
    TreeNode* old_n;
    while(n) {
        if(n->left) {
            old_n = n;
            n = n->left;
            old_n->left = n->right;
            n->right = old_n;
            grand->right = n;
        }
        else {
            ++cnt;
            grand = n;
            n = n->right;
        }
    }
    return cnt;
}

void compress(TreeNode* grand, int m) {
    TreeNode* n = grand->right;
    TreeNode* old_n;
    while(m--) {
        old_n = n;
        n = n->right;
        old_n->right = n->left;
        n->left = old_n;
        grand->right = n;
        grand = n;
        n = n->right;
    }
}

public:TreeNode* balanceBST(TreeNode* root) {
    TreeNode grand;
    grand.right = root;
    int cnt = makeVine(&grand);
    int m = pow(2, (int) log2(cnt + 1)) - 1;
    compress(&grand, cnt - m);
    for(m = m / 2; m > 0; m /= 2)
        compress(&grand, m);
    return grand.right;
}
};