You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

  class Solution {
public:
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(auto list : lists){
            if(list)    pq.push(list);
        }
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        if(pq.empty())   return NULL;

        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            if(top->next)   pq.push(top->next);
            temp->next = top;
            temp = temp->next;
            temp->next = NULL;
        }
        return dummy->next;
    }
};
