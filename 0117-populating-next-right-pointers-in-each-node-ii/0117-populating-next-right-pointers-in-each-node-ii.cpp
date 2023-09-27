class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        queue<Node*> q;
        q.push(root);
        vector<Node*> v;
        unordered_set<int> s;
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                auto* node = q.front(); q.pop();
                v.push_back(node);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            s.insert(v.size() - 1);
        }
        for (int i = 1; i < v.size(); i++)
            if (s.find(i) == s.end())
                v[i]->next = v[i + 1];
        return root;
    }
};