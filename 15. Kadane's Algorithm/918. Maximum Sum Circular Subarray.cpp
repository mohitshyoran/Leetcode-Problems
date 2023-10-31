Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.ake \


// Approach 
//   1. find maxSum , and minSum;
//   2. if subarray is continues answer will bde maxSum
//       or if array is some part from start and ohter part from end it will be totalSum - minSum;
//       so take maximum of both


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0, currMin = 0, currMax = 0, maxSum = INT_MIN, minSum = INT_MAX;

        for(auto num : nums){
            totalSum += num;
            currMin = min(currMin+num, num);
            minSum = min(minSum, currMin);

            currMax = max(currMax+num, num);
            maxSum = max(maxSum, currMax);
        }
        return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
    }
};

