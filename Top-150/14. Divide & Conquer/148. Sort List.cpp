Given the head of a linked list, return the list after sorting it in ascending order.


class Solution {
public:
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        if(l1 == NULL)  return l2;
        if(l2 == NULL)  return l1;
        if(l1->val < l2->val){
            l1->next = mergeList(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeList(l1, l2->next);
            return l2;    
        }
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)    return head;

        ListNode *slow, *fast, *temp;
        slow = fast = head;

        // pointer appraoach / turtle-hare Algorithm (Finding the middle element)
        while(fast && fast->next){
            temp = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        temp->next = NULL;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return mergeList(l1, l2);
    }
};
