class LRUCache {
private:
    struct Node {
        int key, value;
        Node *prev, *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail; // head is LRU

    void moveToHead(Node* node) {
        if (node == head)
            return;
        if (node == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        node->prev = nullptr;
        node->next = head;
        head->prev = node;
        head = node;
    }

    void evict() {
        cache.erase(tail->key);
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
    }

public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        auto* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            auto* newNode = new Node(key, value);
            if (!head) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            cache[key] = newNode;
            if (cache.size() > capacity)
                evict();
        } else {
            auto* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
};