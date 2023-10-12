Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation

// Approach
// one iteration from left - store multiplication of all the elements in left
// second iteration from right - start multiplying elements products from right


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        result[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            result[i] = nums[i-1]*result[i-1];
        }
        int multplier = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            result[i] *= multplier;
            multplier *= nums[i];
        }
        return result;
    }
};
