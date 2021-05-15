There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity. 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size(), mid = 0, num = 0;
        
        while(lo < hi){
            mid = lo + (hi - lo)/2;
            
            if(target < nums[0] == nums[mid] < nums[0]){
                num = nums[mid];
            }
            else {
                // could be nums[0] or nums[mid]
                if(target < nums[mid]){
                    num = INT_MIN; 
                }
                else {
                    num = INT_MAX;
                }
            }
            
            if(num < target){
                lo = mid + 1;
            }
            else if (num > target){
                hi = mid;
            }
            else {
                return mid;
            }
        }
        
        return -1;
    }
};

// first binary search finds the starting position, second binary search find the target element and accounting for rotation.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        
        while(lo < hi){
            int mid = lo + ((hi - lo) >> 1);
            if(nums[mid] > nums[hi]){
                lo = mid + 1;
            }
            else if(nums[mid] <= nums[hi]){
                hi = mid;
            }
            else {
                cout << "unexpected case";
            }            
        }
        
        int start = lo;
        lo = 0, hi = nums.size();
        
        while(lo < hi){
            int mid = lo + ((hi - lo) >> 1);
            int realMid = (mid + start) % nums.size();
            if(nums[realMid] == target){
                return realMid;
            }
            else if(nums[realMid] < target){
                lo = mid + 1;
            }
            else if(nums[realMid] > target){
                hi = mid;
            }
        }
        
        return -1;
    }
};
