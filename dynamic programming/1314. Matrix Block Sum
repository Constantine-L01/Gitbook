Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix. 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

class Solution {
public:
    int sizeX, sizeY;
    int extractSum(int i, int j, const vector<vector<int> >& sum) {
    // if one of the i or j is 0 then need to return since it is out of the matrix
        if (i < 0 || j < 0) return 0;
        if (i >= sizeX) i = sizeX - 1;
        if (j >= sizeY) j = sizeY - 1;
        return sum[i][j];
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        sizeX = mat.size();
        sizeY = mat[0].size();
        
        vector<vector<int>>sum(sizeX, vector<int>(sizeY, 0));
        
        // first, create a prefix-sum array. the value in each index is the sum from 0,0 to i,j
        for(int i = 0; i < sizeX; i++){
            for(int j = 0; j < sizeY; j++){
                sum[i][j] = mat[i][j] + extractSum(i-1, j, sum) + extractSum(i, j-1, sum) - extractSum(i-1, j-1, sum);
            }
        }
        
        vector<vector<int>>ans(sizeX, vector<int>(sizeY, 0));
        
        // ans[i][j] = the sum(i+K, j+K) - the sum -1 y-axis to the area - the sum -1 x-axis to the area + the area that get deducted twice
        for(int i = 0; i < sizeX; i++){
            for(int j = 0; j < sizeY; j++){
                ans[i][j] = extractSum(i+K, j+K, sum) - extractSum(i+K, j-K-1,sum) - extractSum (i-K-1, j+K, sum) + extractSum(i-K-1, j-K-1, sum);                
            }
        }
        
        return ans;
    }
};
