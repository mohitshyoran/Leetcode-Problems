There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal
diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.
Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. 
There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

// Approach - nice logic
// locate arrow at end of first baloon initially.
// Now if starting of ballon is grater than last postion of array we need a new arrow and we will point it to current baloon;s end
// else adjust position of current arrow to min of last position and current baloon;s end so it can brust current baloon as well.

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int end = points[0][1];
        int ans = 0;
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] > end){
                ans++;
                end = points[i][1];
            }
            else{
                end = min(end, points[i][1]);
            }
        }
        return ans+1;
    }
};
