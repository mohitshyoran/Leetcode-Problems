Given a binary tree
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.


// Approach - nice logic
// Maintain on curr node - current node of current level
// One head node - the leading node on the next level
// And one prev node - curr will be linked to prev
// if prev == NUll it means its first node of next level
// now it's simple mapping

class Solution {
public:
    Node* connect(Node* root) {
        Node* prev = NULL; //the leading node on the next level
        Node* head = NULL; //head of the next level
        Node* curr = root; //current node of current level

        while(curr != NULL){
            while(curr != NULL){
                if(curr->left){
                    if(prev)    prev->next = curr->left;
                    else    head = curr->left;
                    prev = curr->left;
                }
                if(curr->right){
                    if(prev)    prev->next = curr->right;
                    else    head = curr->right;
                    prev = curr->right;
                }
                curr = curr->next;
            }
            curr = head;
            prev = head = NULL;
        }
        return root;
    }
};
