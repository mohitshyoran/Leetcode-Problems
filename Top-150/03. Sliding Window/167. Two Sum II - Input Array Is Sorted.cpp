Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 < numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.

// Approch - simple
//   1. keep adding current number
//   2. check if sum >= target after renmoving first number by loop
//   3. after loop check if sum >= target and update ans

  
  
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int sum = 0, i = 0, j = 0;
        while(i <= j && j < nums.size()){
            sum += nums[j];
            while(sum-nums[i] >= target){
                sum -= nums[i];
                i++;
            }
            if(sum >= target)   ans = min(ans, j-i+1);
            j++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
