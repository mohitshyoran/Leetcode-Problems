Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

// Apporach - good logic
//   put all numbers in on lookup set
// if num-1 does not exist means there is chance of starting new chain from here, so keep incresing num by one until nuxt num does not present in lookup table

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup;
        for(auto num : nums) lookup.insert(num);
        int ans = 0, count;

         for(auto num : nums){
             count = 1;
             if(lookup.find(num-1) == lookup.end()){
                 while(lookup.count(num+1) != 0){
                     count++;
                     num++;
                 }
             }
             ans = max(ans, count);
         }
         return ans;
    }
};
