Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

// greedy algorithm
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT32_MAX;
        int sums = 0;
        int subLen = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sums = 0;
            for(int j = i; j < nums.size(); j++) {
                sums += nums[j];
                if (sums >= target) {
                    subLen = j - i + 1;
                    res = min(subLen, res);
                    break;
                }
            }
        }
        
        return res == INT32_MAX ? 0 : res;
    }
};

// sliding window
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT32_MAX;
        int sums = 0;
        int subLen = 0;
        int i = 0;
        
        for(int j = 0; j < nums.size(); j++){
            sums += nums[j];
            // shrink the window by move the left boundary to right.
            while(sums >= target){
                subLen = j - i + 1;
                res = min(res, subLen);
                sums -= nums[i];
                i++;
            }
        }
        
        return res == INT32_MAX ? 0 : res;
    }
};
