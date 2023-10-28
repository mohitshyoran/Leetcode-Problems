Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, 
construct and return the binary tree.
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

// Approach - Same as 106. Construct Binary Tree from Inorder and Preorder Traversal

class Solution {
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left, int right, int &rootIdx){
        if(left > right)    return NULL;
        int pivot = left;
        // fint the root from inOrder
        while(postorder[rootIdx] != inorder[pivot])  pivot++;

        TreeNode* root = new TreeNode(postorder[rootIdx]);
        rootIdx--;

        root->right = build(inorder, postorder, pivot+1, right, rootIdx);
        root->left = build(inorder, postorder, left, pivot-1, rootIdx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIdx = inorder.size()-1, left = 0, right = inorder.size()-1;
        return build(inorder, postorder, left, right, rootIdx);   
    }
};

  
