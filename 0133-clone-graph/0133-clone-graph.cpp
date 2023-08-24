class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;                
        Node* copy = new Node(node->val);
        m[node] = copy;        
        queue<Node*> q;
        q.push(node);        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();            
            for (Node* neighbor:curr->neighbors) {                
                if (m.find(neighbor) == m.end()) {
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }                
                m[curr]->neighbors.push_back(m[neighbor]);
            }
        }        
        return copy;
    }
private:
    unordered_map<Node*, Node*> m;
};