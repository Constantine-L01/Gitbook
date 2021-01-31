Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxCur = nums[0];
        int maxOverall = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
        // nums[i] instead of 0 because there are -ve number. If the current cummulative subarray included the current element is smaller than the current element, 
        // then take the current element as the start of new maximum subarray. 
            maxCur = max(maxCur + nums[i], nums[i]);
        // record the highest subarray   
            maxOverall = max(maxCur, maxOverall);
        }
        
        return maxOverall;
    }
};
