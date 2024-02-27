https://leetcode.com/problems/diameter-of-binary-tree/description/

Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.

class Solution {
    int diameter = 0;
    public int helper(TreeNode root){
        if(root == null)    return 0;
        int left = helper(root.left);
        int right = helper(root.right);
        diameter = Math.max(diameter, left+right);
        return Math.max(left, right)+1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        helper(root);
        return diameter;
    }
}
