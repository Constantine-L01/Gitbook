Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations. 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtracking(vector<int>& candidates, int target, int startIndex, vector<bool>& used){      
        if(target == 0){
            res.push_back(path);
            return;
        }   
                
        for(int i = startIndex; i < candidates.size() && target >= candidates[i]; i++){
            // can exclude because the states will be explored in previous branch. 
            if(i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false){
                continue;
            }            
            target -= candidates[i];
            used[i] = true;
            path.push_back(candidates[i]);
            backtracking(candidates, target, i + 1, used);
            path.pop_back();
            used[i] = false;
            target += candidates[i];
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used);
        return res;
    }
};
