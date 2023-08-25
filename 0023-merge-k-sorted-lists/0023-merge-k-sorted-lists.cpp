class Solution {
private:
    ListNode* mergeHelper(ListNode* leftList, ListNode* rightList) {
        if (leftList == nullptr)
            return rightList;
        if (rightList == nullptr)
            return leftList;
        ListNode* root;
        if (leftList->val <= rightList->val) {
            root = leftList;
            leftList = leftList->next;
        }
        else {
            root = rightList;
            rightList = rightList->next;
        }
        ListNode* tmp = root;
        while(leftList && rightList) {
            if (leftList->val <= rightList->val) {
                tmp->next = leftList;
                leftList = leftList->next;
            }
            else {
                tmp->next = rightList;
                rightList = rightList->next;
            }
            tmp = tmp->next;
        }
        while (leftList) {
            tmp->next = leftList;
            leftList = leftList->next;
            tmp = tmp->next;
        }
        while (rightList) {
            tmp->next = rightList;
            rightList = rightList->next;
            tmp = tmp->next;
        }
        return root;
    }
    ListNode* merge(vector<ListNode*> lists, int low, int high) {
        if (low == high) return lists[low];
        int mid = (low + high) >> 1;
        ListNode* leftList = merge(lists, low, mid);
        ListNode* rightList = merge(lists, mid + 1, high);
        return mergeHelper(leftList, rightList);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }
};