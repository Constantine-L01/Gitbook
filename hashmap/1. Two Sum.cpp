Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            // need to check whether target-nums[i] exists before adding nums[i] into map, so that same element will not be count as twice e.g. target=8 , array=[4, 7]
            if (indices.find(target-nums[i]) != indices.end()) {
                // return indices[target-nums[i]] first since it is the pair added before i
                return {indices[target-nums[i]], i};    
            }
            // add into hashmap
            indices[nums[i]] = i;
        }
        return {};
    }
};
