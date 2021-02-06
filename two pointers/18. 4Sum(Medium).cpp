Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

class Solution {
public:
    vector<vector<int>> nSum(vector<int>& nums, int n, int start, int target){
        int size = nums.size();
        vector<vector<int>> res;
        if (n < 2 || size < n){
            return res;
        }               
        
        if(n==2){
            int lo = start;
            int hi = size - 1;
            while(lo < hi) {
                int sum = nums[lo] + nums[hi];

                if (sum < target) {
                    while(lo < hi && nums[lo] == nums[lo+1]){
                        lo++;
                    }
                    lo++;
                }
                else if (sum > target) {
                    while(lo < hi && nums[hi] == nums[hi-1]){
                        hi--;
                    }
                    hi--;
                }
                else {
                    res.push_back({nums[lo], nums[hi]});
                    while(lo < hi && nums[lo] == nums[lo+1]){
                        lo++;
                    }
                    lo++;
                    while(lo < hi && nums[hi] == nums[hi-1]){
                        hi--;
                    }
                    hi--;
                } 
            }         
        }
        else {            
            // does not need to check for the last n - 1 number because it is the minimal number require to form the remaining sum
            for (int i = start; i < size - n + 1; i++) {
                vector<vector<int>> sub = nSum(nums, n-1, i+1, target-nums[i]);
                for(vector<int>& arr: sub){
                    arr.push_back(nums[i]);
                    res.push_back(arr);
                }
                while(i < size - n + 1 && nums[i] == nums[i+1]){
                    i++;
                }
            }            
        }
         return res; 
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return nSum(nums, 4, 0, target);
    }
};
