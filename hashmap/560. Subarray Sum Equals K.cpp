Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k. 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
  
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> map;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == k){
                count++;
            }
            if(map.find(sum - k) != map.end()){
                count += map[sum - k];
            }
            map[sum]++;
        }
        
        return count;
    }
};
