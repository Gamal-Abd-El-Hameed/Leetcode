class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> result;

        queue<TreeNode*> q;
        q.push(root);

        vector<int> curr;
        int levelSize;
        TreeNode* node;
        while (!q.empty()) {
            levelSize = q.size();
            curr.clear();

            while (levelSize--) {
                node = q.front(); q.pop();

                curr.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            if (!curr.empty())
                result.push_back(curr);
        }

        return result;
    }
};