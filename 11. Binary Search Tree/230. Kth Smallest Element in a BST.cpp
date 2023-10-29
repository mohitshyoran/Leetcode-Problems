Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

// Approach-
//   Inorder solution
// inorder of bst is sorted order, so recursively traverse from left and increment count and once it becomes equal to k return val of that node.


  

//with Helper function and Global variable
class Solution {
public:
    int count = 0, ans;
    void smallest(TreeNode* root, int k){
        if(!root)   return;
        smallest(root->left, k);
        count++;
        if(count == k)  ans = root->val;
        smallest(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        smallest(root, k);
        return ans;
    }
};

//Withoud helper function and global ans variable
class Solution {
public:
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {
        static int count = 0;
        if(!root)   return 0;
        int left = kthSmallest(root->left, k);
        count++;
        if(count == k)  return root->val;
        int right = kthSmallest(root->right, k);
        return max(left, right);
    }
};
