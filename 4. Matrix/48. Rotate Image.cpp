You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Approach - Simple
//   for 90 degree - take transpose and reverse row
//   for 180 degreee - take reverse of row first and then reverse of col
//   for 270/-90 degree - transpose + revers of cols


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(i <= j)  swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

