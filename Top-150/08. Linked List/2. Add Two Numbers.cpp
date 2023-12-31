You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.


  class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head, *temp;
        head = temp = new ListNode();
        int carry = 0, sum = 0;
        while(l1 || l2 || carry){
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }  
            if(carry != 0)  sum += carry;
            temp->next = new ListNode();
            temp = temp->next;
            temp->val = sum %10;
            carry = sum/10; 
            sum = 0;
        }
        return head->next;
    }
};
  

