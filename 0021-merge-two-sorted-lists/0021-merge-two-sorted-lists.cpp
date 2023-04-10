/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(const ListNode* const &list1, const ListNode* const &list2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    const ListNode* current1 = list1;
    const ListNode* current2 = list2;
    while (current1 && current2) {
        if (current1->val < current2->val) {
            tail->next = const_cast<ListNode*>(current1);
            current1 = current1->next;
        } else {
            tail->next = const_cast<ListNode*>(current2);
            current2 = current2->next;
        }
        tail = tail->next;
    }
    if (current1) {
        tail->next = const_cast<ListNode*>(current1);
    } else if (current2) {
        tail->next = const_cast<ListNode*>(current2);
    }
    return dummy.next;
}

};