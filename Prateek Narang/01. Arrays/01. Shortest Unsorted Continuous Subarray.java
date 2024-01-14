https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, 
then the whole array will be sorted in non-decreasing order.
Return the shortest such subarray and output its length.

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

// Approach
// find smallet and largest element which are out of order
// find there correct index and we need to sort all the elements between those index


class Solution {
    public boolean outOfOrder(int[] nums, int i){
        int n = nums.length;
        if(i == 0)  return nums[0] > nums[1];
        else if(i == n-1)   return nums[i] < nums[i-1];
        else{
            return nums[i] < nums[i-1] || nums[i] > nums[i+1];
        }
    }
    public int findUnsortedSubarray(int[] nums) {
        int smallest = Integer.MAX_VALUE, largest = Integer.MIN_VALUE;
        int n = nums.length;
        if(n == 1)  return 0;
        for(int i = 0; i < n; i++){
            if(outOfOrder(nums, i)){
                smallest = Math.min(smallest, nums[i]);
                largest = Math.max(largest, nums[i]);
            }
        }
        if(smallest == Integer.MAX_VALUE)    return 0;
        int left = 0, right = n-1;
        while(left < n && nums[left] <= smallest)   left++;

        while(right >- 0 && nums[right] >= largest) right--;
        return right-left+1;
    }
}
