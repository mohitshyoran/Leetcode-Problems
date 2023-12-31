Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Approch
  1. for every 'O' which is on border do dfs and change all 4 directionaly connected O's to 'Y'
  2. change all 'O' to 'X' now and restore all 'Y' to 'O'

class Solution {
public:
    void bfs(vector<vector<char>> &board, int i, int j){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O')  return;
        board[i][j] = 'Y';
        bfs(board, i+1, j);
        bfs(board, i, j+1);
        bfs(board, i-1, j);
        bfs(board, i, j-1);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && board[i][j] == 'O'){
                    bfs(board, i, j);
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O')  board[i][j] = 'X';
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'Y')  board[i][j] = 'O';
            }
        }
    }
};
