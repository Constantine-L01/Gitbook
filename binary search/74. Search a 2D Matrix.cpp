Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row. 

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int lo = 0, hi = m*n;
        
        while(lo < hi){
            int mid = lo + ((hi - lo) >> 1);
            int midVal = matrix[mid/n][mid%n];
            
            if(midVal == target){
                return true;
            }
            else if(midVal < target){
                lo = mid + 1;
            }
            else if(midVal > target){
                hi = mid;
            }
        }
        
        return false;
    }
};
