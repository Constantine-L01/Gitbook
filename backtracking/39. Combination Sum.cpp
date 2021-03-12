Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtracking(vector<int>& candidates, int target, int startIndex){
        if(target < 0){
            return;
        }
        
        if(target == 0){
            res.push_back(path);
            return;
        }
        
        for(int i = startIndex; i < candidates.size(); i++){
            target -= candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);
            path.pop_back();
            target += candidates[i];
        }
    }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return res;
    }
};

// optimized, need to sort the array first
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtracking(vector<int>& candidates, int target, int startIndex){
        if(target < 0){
            return;
        }
        
        if(target == 0){
            res.push_back(path);
            return;
        }
        
        for(int i = startIndex; i < candidates.size() && target >= candidates[i]; i++){
            target -= candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);
            path.pop_back();
            target += candidates[i];
        }
    }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }
};
