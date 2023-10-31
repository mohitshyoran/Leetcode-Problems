Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.size() == 0)    return res;
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = (l+r)/2;
            if(nums[mid] < target) l = mid+1;
            else r = mid;
        }
        if(nums[l] != target)   return res;
        else res[0] = l;

        r = nums.size()-1;
        while(l < r){
            int mid = (l+r)/2+1;
            if(nums[mid] > target) r = mid-1;
            else l = mid;
        }
        res[1] = r;
        return res;
    }
};
