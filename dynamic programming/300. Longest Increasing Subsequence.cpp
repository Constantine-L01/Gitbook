Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7]. 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
  
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        }
        
        vector<int> dp(nums.size(), 1);
        int result = 0;
        
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if(dp[i] > result){
                result = dp[i];
            }
        }
        
        return result;
    }
};
