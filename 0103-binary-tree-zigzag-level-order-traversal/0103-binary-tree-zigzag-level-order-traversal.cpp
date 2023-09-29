class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        bool rightToLeft = false;
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelValues(levelSize);
            TreeNode* node;
            for (int i = 0; i < levelSize; i++) {
                node = q.front(); q.pop();
                levelValues[i] = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (rightToLeft)
                reverse(levelValues.begin(), levelValues.end());
            res.push_back(levelValues);
            rightToLeft = !rightToLeft;
        }
        return res;
    }
};