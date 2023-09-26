class Solution {
private:
    int getSize(ListNode* head) {
        int size = 0;
        auto curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }
        return size;
    }
    pair<ListNode*, ListNode*> reverseGroup(ListNode* head, int k) {
        ListNode *curr = head, *prev = nullptr, *next;
        while (k--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return {prev, head};
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return nullptr;
        int n = getSize(head);
        k = k % n;
        if (k == 0)
            return head;
        auto pair = reverseGroup(head, n);
        auto curr = pair.first;
        for (int i = 0; i < k; i++)
            curr = curr->next;
        auto leftPair = reverseGroup(pair.first, k);
        auto rightPair = reverseGroup(curr, n - k);
        leftPair.second->next = rightPair.first;
        return leftPair.first;
    }
};