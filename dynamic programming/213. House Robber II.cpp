You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police. 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
  
class Solution {
public:
    int robRange(vector<int>& nums, int start, int end){
        if(start == end){
            return nums[start];
        }
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        
        for(int i = start + 2; i <= end; i++){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        
        return dp[end];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        
        int robFirst = robRange(nums, 0, nums.size() - 2);
        int robSecond = robRange(nums, 1, nums.size() - 1);
        
        return max(robFirst, robSecond);
    }
};
