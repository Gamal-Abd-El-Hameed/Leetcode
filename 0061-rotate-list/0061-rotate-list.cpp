class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        int n = 1;
        auto tail = head;
        while (tail->next) {
            n++;
            tail = tail->next;
        }
        k = k % n;
        if (k == 0)
            return head;
        auto newTail = head;
        for (int i = 0; i < n - k - 1; i++)
            newTail = newTail->next;
        auto newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;
        return newHead;
    }
};