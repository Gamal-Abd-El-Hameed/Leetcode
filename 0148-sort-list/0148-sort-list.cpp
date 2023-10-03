class Solution {
private:
    ListNode* merge(ListNode* head, ListNode* afterMid) {
        if (!head)
            return afterMid;
        if (!afterMid)
            return head;
        auto *left = head, *right = afterMid, *res = new ListNode, *ans = res;
        while (left && right) {
            if (left->val <= right->val) {
                res->next = left;
                left = left->next;
            }
            else {
                res->next = right;
                right = right->next;
            }
            res = res->next;
        }
        while (left) {
            res->next = left;
            left = left->next;
            res = res->next;
        }
        while (right) {
            res->next = right;
            right = right->next;
            res = res->next;
        }
        return ans->next;
    }
    ListNode* getMid(ListNode* head) {
        auto *slow = head, *fast = head, *mid = head;
        while (fast && fast->next) {
            mid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return mid;
    }
    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (head == tail)
            return head;
        auto* mid = getMid(head);
        auto* afterMid = mid->next;
        mid->next = nullptr;
        auto* left = sortList(head, mid);
        auto* right = sortList(afterMid, tail);
        return merge(left, right);
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head)
            return head;
        auto *tail = head;
        while (tail->next)
            tail = tail->next;
        return sortList(head, tail);
    }
};