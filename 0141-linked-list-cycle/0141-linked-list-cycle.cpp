/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (true) {
        if (!slow)
            return false;
        slow = slow->next;
        if (!fast || !(fast->next))
            return false;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
};