class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode* > q;
        q.push(root);
        q.push(nullptr);
        vector<int> tempVector;
        vector<vector<int>> res;
        while(!q.empty()) {
            TreeNode* tempNode = q.front(); q.pop();
            tempVector.push_back(tempNode->val);
            if(tempNode->left)
                q.push(tempNode->left);
            if(tempNode->right)
                q.push(tempNode->right);
            if(!q.front()) {
                res.push_back(tempVector);
                tempVector.clear();
                q.pop();
                if(!q.empty())
                    q.push(nullptr);
            }
        }
        return res;
    }
};