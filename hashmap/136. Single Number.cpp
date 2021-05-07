Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory? 

Example 1:

Input: nums = [2,2,1]
Output: 1

// unordered_map
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        
        for(pair<int, int> mp: map){
            if(mp.second == 1){
                return mp.first;
            } 
        }
        
        return -1;
    }
};

// unordered_set
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
