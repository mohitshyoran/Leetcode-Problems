Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Approach
// Put last node of every level in ans
// or reverse order of pushing nodes in queue and take first element from every level

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)   return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* front = q.front(); 
                q.pop();
                if(i == n-1)    ans.push_back(front->val);
                if(front->left)     q.push(front->left);
                if(front->right)    q.push(front->right);
            }
        }
        return ans;      
    }
};
