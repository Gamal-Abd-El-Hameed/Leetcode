class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0, index, i = 0;
        ListNode* tmp = head;
        while (tmp) {
            size++;
            tmp = tmp->next;
        }
        tmp = head;
        index = size - n;
        if (index == 0)
            return head->next;
        while (i < index - 1) {
            tmp = tmp->next;
            i++;
        }
        tmp->next = tmp->next->next;
        return head;
    }
};