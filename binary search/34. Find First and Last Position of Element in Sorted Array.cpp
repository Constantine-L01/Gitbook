Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity. 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {        
        vector<int> ret(2, -1);
        if(nums.size() == 0){
            return ret;
        }
        
        int lo = 0, hi = nums.size();
        
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target) {
                hi = mid;
            }
            else if(nums[mid] > target){
                hi = mid;
            }
            else if(nums[mid] < target){
                lo = mid + 1;
            }
        }
        
        // later dont need to check lo - 1 < 0 because nums[0] != target if target not found
        if(hi == nums.size() || nums[hi] != target){
            return ret;
        }
        else {
            ret[0] = hi;
        }
        
        hi = nums.size();
        
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target) {
                lo = mid + 1;
            }
            else if(nums[mid] > target){
                hi = mid;
            }
            else if(nums[mid] < target){
                lo = mid + 1;
            }
        }
        
        if(nums[lo - 1] == target){
            ret[1] = lo - 1;
        }
        
        return ret;
    }
};
