class Solution {
private:
    unordered_set<int> visited;
    unordered_map<int, Node*> nodes_map;
    Node* dfs(Node* node) {
        Node* newNode = new Node(node->val);
        visited.insert(node->val);
        nodes_map[node->val] = newNode;
        for (Node* neighbor : node->neighbors) {
            if (visited.find(neighbor->val) != visited.end()) {
                newNode->neighbors.push_back(nodes_map[neighbor->val]);
                continue;
            }
            Node* newNeighbor = dfs(neighbor);
            newNode->neighbors.push_back(newNeighbor);
        }
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        return dfs(node);
    }
};