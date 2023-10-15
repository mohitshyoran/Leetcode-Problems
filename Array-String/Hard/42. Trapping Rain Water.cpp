Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Store max height in left, start from end and keep track of max right height in runtime
// water stored at that index is easy to calculate then

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0);
        left[0] = height[0];
        for(int i = 1; i < height.size(); i++){
            left[i] = max(left[i-1], height[i]);
        }
        int right = 0;
        int ans = 0;
        for(int i = n-1; i >= 0; i--){
            right = max(right, height[i]);
            ans += min(left[i], right) - height[i];
        }
        return ans;
    }
};
