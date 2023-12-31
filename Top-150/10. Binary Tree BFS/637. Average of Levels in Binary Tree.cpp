Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.



class Solution {
public:

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            double sum = 0;
            for(int i = 0; i < n; i++){
                TreeNode* front = q.front(); q.pop();
                sum += front->val;
                if(front->left)     q.push(front->left);
                if(front->right)    q.push(front->right);
            }
            avg.push_back(sum/n);
        }
        return avg;
    }
};
