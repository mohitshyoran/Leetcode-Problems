Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

// Approach - Simple
//   iterate first row and col and store if these should be zero
//   Now store information of other row and col if they should be zero
//   make them zero
//   finally based on first point make first row/col zero

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false, col = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                col = true;break;
            }
        }
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0){
                row = true;break;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(col){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0; 
            }
        }
        if(row){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }
    }
};



