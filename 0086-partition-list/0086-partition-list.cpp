class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto *left = new ListNode, *right = new ListNode, *leftIter = left, *rightIter = right;
        int val;
        while (head) {
            val = head->val;
            if (val < x) {
                leftIter->next = head;
                leftIter = leftIter->next;
            }
            else {
                rightIter->next = head;
                rightIter = rightIter->next;
            }
            head = head->next;
        }
        left = left->next; right = right->next;
        if (!left)
            return right;
        rightIter->next = nullptr;
        leftIter->next = right;
        return left;
    }
};