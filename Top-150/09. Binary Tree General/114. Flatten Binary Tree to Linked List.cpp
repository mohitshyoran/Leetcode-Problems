Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, 
construct and return the binary tree.

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)   return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        //flatten left
        if(left){
            flatten(left);
            //make left null and add left flattend to right
            root->left = NULL;
            root->right = left;
            while(root->right){
                root = root->right;
            }
            root->right = right;
        }
        // flatten right
        flatten(right);
    }
};

