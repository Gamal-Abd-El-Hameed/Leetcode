class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head; // Base case: If the list is empty or has only one node, it is already sorted.
        }

        // Find the middle of the list using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two halves
        prev->next = nullptr;

        // Recursively sort each half
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // Merge the sorted halves
        return merge(left, right);
    }

    // Merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (left && right) {
            if (left->val < right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        if (left) {
            current->next = left;
        }

        if (right) {
            current->next = right;
        }

        return dummy.next;
    }
};