Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.


class Solution {
public:
    TreeNode* bst(vector<int>& nums, int l, int r){
        if(l > r)   return NULL;
        int m = l + (r-l)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = bst(nums, l , m-1);
        root->right = bst(nums, m+1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums, 0, nums.size()-1);
    }
};
