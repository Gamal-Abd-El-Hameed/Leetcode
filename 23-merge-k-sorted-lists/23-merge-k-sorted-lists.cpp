class Solution {
struct compare {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

public:ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> heap;
    for(ListNode* l : lists)
        if(l)
            heap.push(l);
    if(heap.empty())
        return NULL;
    ListNode* root = heap.top();
    heap.pop();
    if(root->next)
        heap.push(root->next);
    ListNode* temp = root;
    while(!heap.empty()) {
        temp->next = heap.top();
        heap.pop();
        temp = temp->next;
        if(temp->next)
            heap.push(temp->next);
    }
    return root;
}
};