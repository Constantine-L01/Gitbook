Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The answer is guaranteed to fit in a 32-bit integer. 

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
  
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i <= target; i++){
            for(int j = 0; j < nums.size(); j++){
                // the remaining for dp[i] need to be enough so overflow will not happen
                if(nums[j] <= i && dp[i] < INT_MAX - dp[i - nums[j]]){
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        
        return dp[target];
    }
};
