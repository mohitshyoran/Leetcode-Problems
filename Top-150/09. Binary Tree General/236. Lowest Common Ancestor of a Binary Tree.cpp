Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL || root == p || root == q)  return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //if left null means one or both node can be in right
        if(left == NULL)    return right;
        //if right null means one or both node can be in left
        else if(right == NULL) return left;
        //if both not null mean found one - one on both side so return root
        else return root;
    }
};
