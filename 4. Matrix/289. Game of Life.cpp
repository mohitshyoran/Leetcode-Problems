According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.


  // Approach 
  // store changed live / dead value in other number(save information)

  class Solution {
public:
    vector<int> di = {0,0,1,-1,1,-1,1,-1};
    vector<int> dj = {1,-1,0,0,1,1,-1,-1};
    int live(vector<vector<int>>& board, int i, int j){
        int count = 0;
        for(int c = 0; c < 8; c++){
            int ni = i + di[c];
            int nj = j + dj[c];
            if(ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size()){
                if(board[ni][nj] == 1 || board[ni][nj] == 3) count++;
            }
        }
        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int lives = live(board, i, j);
                if(board[i][j] == 1 && (lives < 2 || lives > 3))   board[i][j] = 3;
                else if(board[i][j] == 0 && lives == 3)   board[i][j] = 2;
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 2)    board[i][j] = 1;
                if(board[i][j] == 3)    board[i][j] = 0;
            }
        }
    }
};
