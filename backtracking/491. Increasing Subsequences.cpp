Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2.

Example:

Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtracking(vector<int>& nums, int startIndex) {
        if(path.size() > 1){
            res.push_back(path);
        }
        
        unordered_set<int> uset;
        
        for(int i = startIndex; i < nums.size(); i++){
            if((!path.empty() && nums[i] < path.back()) || (uset.find(nums[i]) != uset.end())){
                continue;
            }
            path.push_back(nums[i]);
            uset.insert(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};

// optimized solution
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtracking(vector<int>& nums, int startIndex) {
        if(path.size() > 1){
            res.push_back(path);
        }
        
        // need to be 201 because 1 to 100 is 100 elements, -1 to -100 is 100 elements, add up 0 becomes 201
        int used[201] = {0};
        
        for(int i = startIndex; i < nums.size(); i++){
            // need to + 100 since indexing starts at 0 
            if((!path.empty() && nums[i] < path.back()) || used[nums[i] + 100] == 1){
                continue;
            }
            path.push_back(nums[i]);
            used[nums[i] + 100] = 1;
            backtracking(nums, i + 1);            
            path.pop_back();
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};
