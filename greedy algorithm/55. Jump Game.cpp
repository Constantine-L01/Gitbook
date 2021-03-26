Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index. 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
  
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if(nums.size() == 1) {
            return true;
        }
        
        for(int i = 0; i <= cover; i++){
            cover = max(i + nums[i], cover);
            if(cover >= (nums.size() - 1)) {
                return true;
            }
        }
        
        return false;
    }
};
