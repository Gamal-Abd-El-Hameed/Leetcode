class BSTIterator {
    priority_queue<int, vector<int>, greater<>> q;
public:
    BSTIterator(TreeNode* root) {
        queue<TreeNode*> tempQ;
        tempQ.push(root);
        while (!tempQ.empty()) {
            auto* curr = tempQ.front(); tempQ.pop();
            q.push(curr->val);
            if (curr->left)
                tempQ.push(curr->left);
            if (curr->right)
                tempQ.push(curr->right);
        }
    }

    int next() {
        int val = q.top();
        q.pop();
        return val;
    }

    bool hasNext() {
        return !q.empty();
    }
};