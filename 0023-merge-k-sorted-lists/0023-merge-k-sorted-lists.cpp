class Solution {
private:
    ListNode* mergeTwoLists(ListNode* leftList, ListNode* rightList) {
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
        if (leftList)
            tmp->next = leftList;
        if (rightList)
            tmp->next = rightList;
        return root;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        vector<ListNode*> mergedLists;
        ListNode *leftList, *rightList;
        while (lists.size() > 1) {
            mergedLists.clear();
            for (int i = 0; i < lists.size(); i += 2) {
                leftList = lists[i];
                if (i + 1 < lists.size())
                    rightList = lists[i + 1];
                else
                    rightList = nullptr;
                mergedLists.push_back(mergeTwoLists(leftList, rightList));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
};