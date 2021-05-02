Given an m x n matrix board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region. 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

class Solution {
    public:        
    void DFS(vector<vector<char>>& board, int i, int j, int m, int n){
        if((i < 0 or j < 0 or i >= m or j >= n) or board[i][j] != 'O' ){
            return;
        }
        
        board[i][j] = '#';
        DFS(board, i - 1, j, m, n);
        DFS(board, i + 1, j, m, n);
        DFS(board, i, j - 1, m, n);
        DFS(board, i, j + 1, m, n);
        
        return;
    }    
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) {
            return;
        }
        int n = board[0].size();
        
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                DFS(board, i, 0, m, n);
            }
            if(board[i][n - 1] == 'O'){
                DFS(board, i, n - 1, m, n);
            }
        }
        
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                DFS(board, 0, j, m, n);
            }
            if(board[m - 1][j] == 'O'){
                DFS(board, m - 1, j, m, n);
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
