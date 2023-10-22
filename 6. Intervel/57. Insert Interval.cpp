You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti.
You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

// Approach - Nice Logic
// at every interval take decesion what interval will go in answer array and what interval will be left to be merge in coming intervals.

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i = 0; i < intervals.size(); i++){
            vector<int> interval = intervals[i];
            if(interval[1] < newInterval[0]){
                ans.push_back(interval);
            } else if(interval[0] > newInterval[1]){
                ans.push_back(newInterval);
                newInterval = interval;
            }else{
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};
