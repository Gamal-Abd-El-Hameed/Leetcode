class Solution {
private:
    int size = 0;
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current) {
            size++;
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode* res = head;
        ListNode* headCopy = new ListNode (head->val);
        ListNode* tmp;
        tmp = head->next;
        ListNode* headCopyTemp = headCopy;
        while (tmp) {
            headCopyTemp->next = new ListNode(tmp->val);
            tmp = tmp->next;
            headCopyTemp = headCopyTemp->next;
        }
        ListNode* tail = reverseList(headCopy);
        head = head->next;
        tmp = res;
        int i = 1;
        while(i < size) {
            if (i % 2) {
                tmp->next = tail;
                tail = tail->next;
            }
            else {
                tmp->next = head;
                head = head->next;
            }
            i++;
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        head = res;
    }
};