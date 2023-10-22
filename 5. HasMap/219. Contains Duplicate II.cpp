Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Approach - Simple
  //store index of every number and check if current number occures pervioulsy and get index from map find differnece with current index.
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.count(nums[i]) != 0){
                if(abs(mp[nums[i]] - i) <= k )  return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};
