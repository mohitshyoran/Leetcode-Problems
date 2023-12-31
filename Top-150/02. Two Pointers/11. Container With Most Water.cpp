You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

// Approach - Simple
// take first and last wall in starting
// now chances of increasing stored water is only when you eleiminate smaller wall.
// accordginaly increase/decrease i, j

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int ans = 0;
        while( i < j){
            ans = max(ans, min(height[i], height[j])*(j-i));
            if(height[i] > height[j])   j--;
            else    i++;
        }
        return ans;
    }
};


