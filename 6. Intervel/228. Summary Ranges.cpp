You are given a sorted unique integer array nums.
A range [a,b] is the set of all integers from a to b (inclusive).
Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b

Example 1:
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int a = nums[0], n = nums.size();
        if(n == 0)  return ans;
        for(int i = 0; i < n; i++){
            if(i == n-1 || nums[i+1] != nums[i]+1){
                if(a == nums[i]){
                    ans.push_back(to_string(a));
                }else{
                    ans.push_back(to_string(a) + "->" + to_string(nums[i]));
                }
                if(i != n-1)    a = nums[i+1];
            }
        }
        return ans;
    }
};
