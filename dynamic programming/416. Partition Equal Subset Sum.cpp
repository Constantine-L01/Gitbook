Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal. 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        
        if(sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        
        vector<int> dp(target + 1, 0);
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = target; j >= nums[i]; j--){
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        
        if(dp[target] == target){
            return true;
        }
        else {
            return false;
        }
    }
};
