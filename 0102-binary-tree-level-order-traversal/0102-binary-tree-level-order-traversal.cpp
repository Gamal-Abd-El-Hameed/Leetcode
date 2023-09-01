class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);

        TreeNode* node;
        int level;
        while (!q.empty()) {
            node = q.front().first;
            level = q.front().second;
            q.pop();

            if (result.size() == level) {
                result.emplace_back();
            }

            result[level].push_back(node->val);

            if (node->left) {
                q.emplace(node->left, level + 1);
            }
            if (node->right) {
                q.emplace(node->right, level + 1);
            }
        }

        return result;
    }
};