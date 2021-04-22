Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.

A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1]. 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5] with length 3.
Even though [1,3,5,7] is an increasing subsequence, it is not continuous as elements 5 and 7 are separated by element
4.

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 1){
            return n;
        }
        
        vector<int> dp(n, 1);
        int result = 1;
        
        for(int i = 0; i < n - 1; i++){
            if(nums[i + 1] > nums[i]){                
                dp[i + 1] = dp[i] + 1;
            }
            result = max(result, dp[i + 1]);
        }
        
        return result;
    }
};
