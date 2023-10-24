A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node.
Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.


// Approach
// 1. Iterate the original list and duplicate each node. The duplicate
// of each node follows its original immediately.
// 2. Iterate the new list and assign the random pointer for each duplicated node.
// 3. Restore the original list and extract the duplicated nodes.

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        //Insert Duplicate
        while(temp){
            Node* mid = new Node(temp->val);
            mid->next = temp->next;
            temp->next = mid;
            temp = mid->next;
        }

        //Assign random
        temp = head;
        while(temp){
            if(temp->random == NULL){
                temp->next->random = temp->random;
            }
            else{
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        //Extract deep copy and original
        temp = head;
        Node *newHead = new Node(0);
        Node *temp2 = newHead;
        while(temp){
            temp2->next = temp->next;
            temp2 = temp2->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        return newHead->next;;
    }
};

