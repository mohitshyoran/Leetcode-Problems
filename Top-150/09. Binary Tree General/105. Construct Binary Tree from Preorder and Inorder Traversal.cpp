Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree,
construct and return the binary tree.

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]


class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right, int &rootIdx){
        if(left > right)    return NULL;
        int pivot = left;
        // fint the root from inOrder
        while(preorder[rootIdx] != inorder[pivot])  pivot++;

        TreeNode* root = new TreeNode(preorder[rootIdx]);
        rootIdx++;

        root->left = build(preorder, inorder, left, pivot-1, rootIdx);
        root->right = build(preorder, inorder, pivot+1, right, rootIdx);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int rootIdx = 0, left = 0, right = inorder.size()-1;
         return build(preorder, inorder, left, right, rootIdx);  
    }
};
  
