class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        queue<Node*> q;
        q.push(root);
        vector<Node*> v;
        while (!q.empty()) {
            auto* node = q.front(); q.pop();
            v.push_back(node);
            if (node->left) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        for (int i = 1; i < v.size(); i++) {
            if (i + 2 & i + 1) {
                v[i]->next = v[i + 1];
            }
        }
        return root;
    }
};