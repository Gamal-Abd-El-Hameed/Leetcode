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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        auto* curr = new ListNode(0);
        ListNode* head = curr;
        while (true) {
            if (list1->val <= list2->val) {
                curr->val = list1->val;
                list1 = list1->next;
                if (list1 == nullptr) {
                    curr->next = list2;
                    break;
                }
            }
            else {
                curr->val = list2->val;
                list2 = list2->next;
                if (list2 == nullptr) {
                    curr->next = list1;
                    break;
                }
            }
            curr->next = new ListNode(0);
            curr = curr->next;
        }
        return head;
    }
};