Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory? 

Example 1:

Input: nums = [2,2,1]
Output: 1
  
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        
        for(int i = 0; i < nums.size(); i++){
            if(set.find(nums[i]) == set.end()){
                set.insert(nums[i]);
            }
            else {
                set.erase(nums[i]);
            }
        }
        
        std::unordered_set<int>::iterator ret = set.begin();
        return *ret;
    }
};

// can solve with unordered_map and unordered_set too
