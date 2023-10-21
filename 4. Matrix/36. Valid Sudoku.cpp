Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.


// Approach
// // create notaion of 3 types - 
// 1. number presten in i th row - something like "row4val6"
// 2. number present in ith col - something like "col7val1"
// 3. number prestnt in ith box - something like "box2val8"
// store in set and if find again in set return false;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
        // declare a set
        unordered_set<string> s;
        
        // box number for any cell [i, j] is (i / 3) * + j / 3, taking (3 * 3) boxes
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(mat[i][j] != '.')
                {
                    // if the curr number is already present in set
                    if(s.count("row" + to_string(i) + "*" + to_string(mat[i][j])))  return false;
                    if(s.count("col" + to_string(j) + "*" + to_string(mat[i][j])))  return false;
                    if(s.count("box" + to_string((i / 3) * 3 + j / 3) + "*" + to_string(mat[i][j])))    return false;
                    
                    // insert the curr number in set with row no., col no., box no.
                    s.insert("row" + to_string(i) + "*" + to_string(mat[i][j]));
                    s.insert("col" + to_string(j) + "*" + to_string(mat[i][j]));
                    s.insert("box" + to_string((i / 3) * 3 + j / 3) + "*" + to_string(mat[i][j]));
                }
            }
        }
        return true;
    }
};

