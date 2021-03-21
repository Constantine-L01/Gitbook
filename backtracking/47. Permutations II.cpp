Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order. 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false){
                continue;
            }
            
            // the current element may be used in upper level
            if(used[i] == false){
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false; 
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return res;
    }
};

// another solution
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            // there will be a pair of path with the same ordering, thus we remove one path which take previous element first. 
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == true){
                continue;
            }
            
            if(used[i] == false){
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false; 
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return res;
    }
};
