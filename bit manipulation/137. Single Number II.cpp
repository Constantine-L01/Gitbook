Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space. 

Example 1:

Input: nums = [2,2,3,2]
Output: 3

// not constant space, space complexity = O(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(map[nums[i]] == 1){
                return nums[i];
            }
        }
        
        return -1;
    }
};
