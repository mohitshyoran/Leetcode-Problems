Given the head of a linked list, remove the nth node from the end of the list and return its head.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        while(n-- > 0){
            fast = fast->next;
        }
        if(!fast) return head->next;

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next= slow->next->next;
        return head;
    }
};
