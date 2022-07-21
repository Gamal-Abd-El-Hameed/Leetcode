class Solution {
    TreeNode* helper(ListNode *head, ListNode *tail) {
    if(head == tail)
        return nullptr;
    if(head->next == tail)
        return new TreeNode(head->val);
    ListNode *mid = head, *temp = head;
    while(temp != tail && temp->next != tail) {
        mid = mid->next;
        temp = temp->next->next;
    }
    TreeNode *root = new TreeNode(mid->val);
    root->left = helper(head, mid);
    root->right = helper(mid->next, tail);
    return root;
}
public:
TreeNode* sortedListToBST(ListNode* head) {
    return helper(head, nullptr);
}
};