https://www.interviewbit.com/problems/k-reverse-linked-list/

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,
You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

https://www.interviewbit.com/problems/k-reverse-linked-list/

//  revere k elements, head will be tail now, and prev will be tail after reversal
//  just algin pointer and do next call
public class Solution {
    public ListNode reverseList(ListNode A, int B) {
        if(A == null)   return A;
        
        ListNode curr = A;
        ListNode prev = null;
        ListNode next = null;
        
        int k = 1;
        while(curr != null && k <= B){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
            k++;
        }
        
        if(curr != null){
            A.next = reverseList(curr, B);
        }
        return prev;
    }
}
