Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

// solution that need to consider square matrix with odd column and row that will leave middle position untouched
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // loop = n/2 because every loop will eliminate 2 columns and 2 row.
        int loop = n/2;
        // mid = n/2 will be fine as 0 will count as first element
        int mid = n/2;
        int offset = 1;
        int startX = 0;
        int startY = 0;
        vector<vector<int>> res(n, vector<int>(n, 0));
        int count = 1;
        int i = 0, j = 0;
        
        while(loop) {
            for(j = startY; j < startY + n - offset; j++) {
                res[startX][j] = count++;        
            }
            
            for(i = startX; i < startX + n - offset; i++) {
                res[i][j] = count++;
            }
            
            for(; j > startY; j--) {
                res[i][j] = count++;
            }
            
            for(; i > startX; i--) {
                res[i][j] = count++;
            }
            
            loop--;
            startY++;
            startX++;
            offset += 2;
        }
        
        if(n%2) {
            res[mid][mid] = count;
        }
        
        return res;
    }
};
