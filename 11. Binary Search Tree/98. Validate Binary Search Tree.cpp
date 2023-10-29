Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


// Approach1 - most optimized
// Traverse inorder , store last node of inorder and return false if it is not smaller than current root.
// if recieve false from either left or right return false else return true;

class Solution {
public:
    TreeNode* last = NULL;
    //Traverse Inorder
    bool isValidBST(TreeNode* root) {
        if(!root)   return true;
        bool left = isValidBST(root->left);
        if(last != NULL && last->val >= root->val)   return false;
        last = root;
        bool right = isValidBST(root->right);
        //if failed at either left or at right return false
        if(!left || !right) return false;
        //else return true;
        return true;
    }
};


// Approch - 2
//   Pass Min node and max node value at every call and check if condition faling

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }

    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) return true;
        if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};
