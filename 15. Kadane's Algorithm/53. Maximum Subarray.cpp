Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        for(auto num : nums){
            if(sum < 0){
                sum = 0;
            }
            sum += num;
            maxSum = max(maxSum , sum);
        }
        return maxSum;
    }
};
