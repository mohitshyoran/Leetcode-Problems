Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(end < intervals[i][0]){
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }else{
                end = max(intervals[i][1], end);
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};


//Approach - 2 ,nice one - slight modification of insert interval
// consider first interval as newInterval and merge it to array of intervals staring form index 1

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        vector<int>& newInterval = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
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


