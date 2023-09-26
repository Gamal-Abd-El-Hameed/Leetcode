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
        return {head, prev};
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto res = head;
        int size = getSize(head);
        int numOfReverses = size / k;
        ListNode *curr = head, *lastTail = nullptr;
        bool firstReverse = true;
        while (numOfReverses--) {
            auto tailNext = curr;
            for (int i = 0; i < k; i++)
                tailNext = tailNext->next;
            auto pair = reverseGroup(curr, k);
            if (firstReverse) {
                res = pair.second;
                firstReverse = false;
            }
            pair.first->next = tailNext;
            curr = tailNext;
            if (lastTail) {
                lastTail->next = pair.second;
            }
            lastTail = pair.first;
        }
        return res;
    }
};