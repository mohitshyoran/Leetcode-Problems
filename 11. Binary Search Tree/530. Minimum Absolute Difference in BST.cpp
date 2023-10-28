Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

// Approach - Nice Logic
// Taverse inorder, here whatever last traverse node we will store in one variable that will be just smnaller than current in inorder
// So we can take difference of current node and last traversed node and update ans 




class Solution {
public:
    TreeNode* last = NULL;
    int ans = INT_MAX;
    void inorder(TreeNode* root){
        if(!root)   return;
        inorder(root->left);
        if(last != NULL){
            ans = min(ans, abs(last->val - root->val));
        }
        last = root;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
