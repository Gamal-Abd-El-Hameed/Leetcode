class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while (!q.empty()) {
            int levelSize = q.size();
            TreeNode* node;
            for (int i = 0; i < levelSize; i++) {
                node = q.front(); q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(node->val);
        }
        return res;
    }
};