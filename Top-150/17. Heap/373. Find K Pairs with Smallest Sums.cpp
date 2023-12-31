You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
Define a pair (u, v) which consists of one element from the first array and one element from the second array.
Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]


class Solution {
public:
    struct compare{
        bool operator()(const vector<int> a, const vector<int> b){
            return a[0]+a[1] > b[0]+b[1];
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;

        vector<vector<int>> ans;
        // push ith numer from num1, 0th from num2 and index of num2(0);
        for(int i = 0; i < nums1.size() && i < k; i++) pq.push({nums1[i], nums2[0], 0});

        while(k-- > 0 && !pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();
            ans.push_back({curr[0], curr[1]});
            if(curr[2] == nums2.size()-1)   continue;
            int nextIndex = curr[2]+1;
            // push with next number from num2 with it's index
            pq.push({curr[0], nums2[nextIndex], nextIndex});
        }
        return ans;
    }
};


