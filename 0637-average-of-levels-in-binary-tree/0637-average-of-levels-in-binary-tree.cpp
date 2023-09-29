class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> res;
        while (!q.empty()) {
            int levelSize = q.size();
            double sum = 0.0;
            for (int i = 0; i < levelSize; i++) {
                auto* node = q.front(); q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(sum / levelSize);
        }
        return res;
    }
};