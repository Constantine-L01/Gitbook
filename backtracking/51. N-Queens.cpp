The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively. 

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

class Solution {
public:
    vector<vector<string>> res;
    vector<string>* chessboard;
    
    void backtracking(int n, int row){
        if(row == n){
            res.push_back(*chessboard);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(isValid(row, i, n)){
                (*chessboard)[row][i] = 'Q';
                backtracking(n, row + 1);
                (*chessboard)[row][i] = '.';
            }
        }
    }
    
    bool isValid(int row, int col, int n){
        for(int i = 0; i < row; i++){
            if((*chessboard)[i][col] == 'Q') {
                return false;
            }
        }
        
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if((*chessboard)[i][j] == 'Q'){
                return false;
            }
        }
        
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if((*chessboard)[i][j] == 'Q'){
                return false;
            }
        }        
        return true;
    }    
    
    vector<vector<string>> solveNQueens(int n) {
        chessboard = new vector<string>(n, string(n, '.'));
        backtracking(n, 0);
        return res;
    }
};
