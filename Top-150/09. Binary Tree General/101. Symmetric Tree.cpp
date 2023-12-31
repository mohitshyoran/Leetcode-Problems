Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

class Solution {
public:
    bool isSymmetricUtil(TreeNode* root1, TreeNode* root2){
        if((root1 && !root2) || (!root1 && root2))  return false;
        else if(!root1 && !root2)   return true;
        else if(root1->val != root2->val)   return false;

        return isSymmetricUtil(root1->left, root2->right) && isSymmetricUtil(root1->right, root2->left); 
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetricUtil(root->left, root->right);
    }
};
