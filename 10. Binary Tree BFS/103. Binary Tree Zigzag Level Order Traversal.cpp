Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

// Approach 
// Small change from level order
// if levels are even fill values in array from end


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)   return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            int n = q.size();
            vector<int> level(n);
            for(int i = 0; i < n; i++){
                TreeNode* front = q.front(); 
                q.pop();

                if(flag)    level[n-i-1] = front->val;
                else    level[i] = front->val;   

                if(front->left)     q.push(front->left);
                if(front->right)    q.push(front->right);
            }
            flag = !flag;
            ans.push_back(level);
        }
        return ans;
    }
};
