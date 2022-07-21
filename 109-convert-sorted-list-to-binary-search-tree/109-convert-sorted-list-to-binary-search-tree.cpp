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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* helper(unordered_map<int, ListNode*> &m, int start, int end) {
        if(start > end)
            return NULL;
        int mid = (start + end) >> 1;
        TreeNode* root = new TreeNode(m[mid]->val);
        root->left = helper(m, start, mid - 1);
        root->right = helper(m, mid + 1, end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        unordered_map<int, ListNode*> m;
        ListNode* temp = head;
        int i = 0;
        while(temp) {
            m[i] = temp;
            temp = temp->next;
            ++i;
        }
        return helper(m, 0, i - 1);
    }
};