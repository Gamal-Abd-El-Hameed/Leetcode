class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        multimap<int, ListNode*> mp;  //a new multimap<val, head> to store data
        for (auto p : lists) {
            if (p != NULL) { //every List , <val, ListHead>, if ListHead != NULL
                mp.insert(make_pair(p->val, p)); 
            }
        }
        ListNode *ret = NULL;
        ListNode *p = NULL;
        while (!mp.empty()) {
            multimap<int, ListNode*>::iterator it = mp.begin();
//it is the iterator of max value, because map use RB tree to implement
            if (ret == NULL) {
                ret = it->second;
                p = ret;
            } else {
                p->next = it->second;
                p = p->next;
            }
            if (it->second->next != NULL) {
                mp.insert(make_pair(it->second->next->val, it->second->next));
            } //add the next node of the max value of list 
            mp.erase(it); //delete the max value which already add the result list
        }
        return ret;
    }
};