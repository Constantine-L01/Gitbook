Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules. 

Example 1:

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int usedRow[9][9] = {0}, usedCol[9][9] = {0}, usedSquare[9][9] = {0};
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0' - 1, k = i/3 * 3 + j/3;
                    if(usedRow[i][num] || usedCol[j][num] || usedSquare[k][num]){
                        return false;
                    }
                    else {
                        usedRow[i][num] = usedCol[j][num] = usedSquare[k][num] = 1;
                    }
                }
            }
        }
        
        return true;
    }
};
