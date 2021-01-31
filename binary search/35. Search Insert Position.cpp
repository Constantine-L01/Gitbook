Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1; // 定义target在左闭右闭的区间里，[left, right] 
        while (left <= right) { // 当left==right，区间[left, right]依然有效
            // in the case of left and right pointer point to neighbouring element, then middle will be left pointer because the division will act as ceiling function. 
            int middle = left + ((right - left) / 2); // 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                // (case: both pointer point to neighbouring element) if the element before right is larger than target, then point the right pointer to the element.
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                // (case: both pointer point to neighbouring element) if the element point by left/middle pointer is smaller than target, then increment left pointer by one. 
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else { // nums[middle] == target
                return middle;
            }
        }
        
        // for element not found, left pointer will be incremented by one first, then decrement right pointer by one because the target is between the range of left and right pointer.
        // the ending case is [right + 1, right], thus could return right + 1 too because left == right + 1. Cannot return right because right pointer had been decremented to the left 
        // boundary but we need right boundary because the number should be insert at position greater than lower boundary. 
        return left;
    }
};
