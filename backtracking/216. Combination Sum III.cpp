Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

    Only numbers 1 through 9 are used.
    Each number is used at most once.

Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
  
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtrack(int targetSum, int k, int startIndex) {
        if(path.size() == k){
            if(targetSum == 0){
                res.push_back(path);            
            }
         return;
        }       

        for(int i = startIndex; i <= 9; i++){
            targetSum -= i;
            path.push_back(i);
            backtrack(targetSum, k, i + 1 );
            targetSum += i;
            path.pop_back();
        }        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(n, k, 1);
        return res;
    }
};

// optimized
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtrack(int targetSum, int k, int startIndex) {
        if(targetSum < 0){
            return;
        }
        
        if(path.size() == k){
            if(targetSum == 0){
                res.push_back(path);            
            }
         return;
        }       

        for(int i = startIndex; i <= 9; i++){
            targetSum -= i;
            path.push_back(i);
            backtrack(targetSum, k, i + 1 );
            targetSum += i;
            path.pop_back();
        }        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(n, k, 1);
        return res;
    }
};
