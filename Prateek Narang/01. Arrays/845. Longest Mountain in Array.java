You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.


// Approach
// Find peak - move forward, backward and check

  class Solution {
    public boolean isPeak(int[] arr, int i){
        int n = arr.length;
        if(i == 0 || i == n-1){
            return false;
        }else{
            return arr[i] > arr[i-1] && arr[i] > arr[i+1];
        }
    }
    public int longestMountain(int[] arr) {
        int ans = 0, i = 0, n = arr.length;
        while(i < n){
            if(isPeak(arr, i)){
                int j = i;
                while(j > 0 && arr[j] > arr[j-1]){
                    j--;
                }
                while(i < n-1 && arr[i] > arr[i+1]){
                    i++;
                }
                int currLen = i-j+1;
                ans = Integer.max(ans, currLen);
            }
            i++;
        }
        return ans;
    }
}


