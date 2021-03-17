Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool>* used;
    
    void backtracking(vector<int>& nums, int startIndex){
        res.push_back(path);
        for(int i = startIndex; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1] && (*used)[i - 1] == false){
                continue;
            }
            path.push_back(nums[i]);
            (*used)[i] = true;
            backtracking(nums, i + 1);
            (*used)[i] = false;
            path.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        used = new vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return res;
    }
};
