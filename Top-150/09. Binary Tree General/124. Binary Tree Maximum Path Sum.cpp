A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
  A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.

class Solution {
public:
    int ans = INT_MIN;
    int maxPathSumUtil(TreeNode* root){
        if(!root)   return 0;

        int left = max(0, maxPathSumUtil(root->left)); // to avoid adding negetive
        int right = max(0, maxPathSumUtil(root->right)); // to avoid adding negetive
        ans = max(ans, left+right+root->val);

        return max(left+root->val, right+root->val);
    }
    int maxPathSum(TreeNode* root) {
        maxPathSumUtil(root);
        return ans;
    }
};

