You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]


// Iterative Approach

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head, *temp;
        head = temp = new ListNode();
        while(list1|| list2){
            if(list1 != NULL && list2 != NULL){
                if(list1->val < list2->val){
                    temp->next = list1;
                    list1 = list1->next;
                }else{
                    temp->next = list2;
                    list2 = list2->next;
                }
            }
            else if(list1){
                temp->next = list1;
                list1 = list1->next;
            }
            else if(list2){
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        return head->next;
    }
};



// Recurcive Approach

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)   return list2;
        if(list2 == NULL)   return list1;

        if(list1->val < list2->val){
           list1->next = mergeTwoLists(list1->next, list2);
           return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
