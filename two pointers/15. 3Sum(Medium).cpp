Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

class Solution {
public:
    vector<vector<int>> nSum(vector<int>& nums, int n, int start, int target){
        int size = nums.size();
        vector<vector<int>> res;
        if (n < 2 || size < n) {
            return res;
        }
        
        if (n == 2) {
            int lo = start;
            int hi = size - 1;
            while(lo < hi) {
                int sum = nums[lo] + nums[hi];               
                if (sum < target) {
                    while(lo < hi && nums[lo] == nums[lo+1]) {
                        lo++;
                    }
                    // go to the next different character
                    lo++;
                }
                else if (sum > target) {
                    while(lo < hi && nums[hi] == nums[hi-1]) {
                        hi--;
                    }
                    hi--;
                }
                else {
                    res.push_back({nums[lo], nums[hi]});
                    while(lo < hi && nums[lo] == nums[lo+1]) {
                        lo++;
                    }
                    lo++;
                    while(lo < hi && nums[hi] == nums[hi-1]) {
                        hi--;
                    }
                    hi--;
                }
            }
        }
        else {
            for(int i = start; i < size; i++) {
                vector<vector<int>> sub = nSum(nums, n-1, i+1, target-nums[i]);
                for(vector<int>& arr: sub){
                    arr.push_back(nums[i]);
                    res.push_back(arr);
                }
                while(i < size-1 && nums[i] == nums[i+1]){
                    i++;
                }
            }
        }
        return res;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nSum(nums, 3, 0, 0);
    }
};
