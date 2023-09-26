class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head, *ans = new ListNode, *ansTemp = ans;
        int prevVal = -101;
        while (curr) {
            if ((prevVal != curr->val && !curr->next) || (prevVal != curr->val && curr->next && curr->next->val != curr->val)) {
                ansTemp->next = curr;
                ansTemp = ansTemp->next;
            }
            prevVal = curr->val;
            curr = curr->next;
        }
        ansTemp->next = nullptr;
        return ans->next;
    }
};