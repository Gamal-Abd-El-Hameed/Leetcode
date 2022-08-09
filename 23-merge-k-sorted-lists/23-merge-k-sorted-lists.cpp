class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* h1,ListNode* h2){
        if(h1 == NULL)return h2;
        if(h2 == NULL)return h1;
        ListNode* hf;
        if(h1->val <= h2->val){
            hf = h1;
            h1 = h1->next;
        }else{
            hf = h2;
            h2 = h2->next;
        }
        ListNode* ht = hf;
        while(h1 != NULL && h2 != NULL){
            if(h1->val <= h2->val){
                ht->next = h1;
                ht = ht->next;
                h1 = h1->next;
            }
            else{
                ht->next = h2;
                ht = ht->next;
                h2 = h2->next;
            }
        }
        if(h1 == NULL){
            ht->next = h2;
        }
        else{
            ht->next = h1;
        }
        return hf;
    }
    
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)return NULL;
        ListNode* hf = lists[0];
        for(int i = 1;i < lists.size();i++){
            hf = mergeTwoLists(hf,lists[i]);
        }
        return hf;
    }
};