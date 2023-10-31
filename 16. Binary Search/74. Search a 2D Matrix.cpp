You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m*n-1;
        while(l <= r){
            int mid = (l+r)/2;
            int row = mid/n, col = mid%n;
            if(matrix[row][col] == target)  return true;
            else if(target > matrix[row][col])   l = mid+1;
            else r = mid-1;
        }
        return false;
    }
};
