A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with two or fewer elements is trivially a wiggle sequence.

    For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
    In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.

A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums. 

Example 1:

Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).
  
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        }
        
        int currDiff = 0;
        int preDiff = 0;
        int result = 1;
        
        for(int i = 1; i < nums.size(); i++){
            currDiff = nums[i] - nums[i - 1];
            // it will always check for only 1 peak element as result = 1 will include the left side and the invariant hold
            if(preDiff >= 0 && currDiff < 0 || preDiff <= 0 && currDiff > 0){
                result++;
                preDiff = currDiff;
            }
        }
        
        return result;
    }
};
