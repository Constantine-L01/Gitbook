Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k. 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

// TTL
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        int presum[n + 1];
        // need to have first element to be zero
        presum[0] = 0;
        int count = 0;
        
        for(int i = 0; i < n; i++){
            presum[i + 1] = presum[i] + nums[i];
        }
        
        // then i start at 1 and j start at 0 so can detect the case when just one element is equal to k i.e. presum[1] - presum[0] 
        for(int i = 1; i <= nums.size(); i++){
            for(int j = 0; j < i; j++){                
                if(presum[i] - presum[j] == k){
                    count++;    
                }
            }
        }

        return count;
    }
};

// TTL
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i - 1];
        }
        
        for(int i = 0; i < nums.size(); i++){
            // cover the cases where subarray starts at first element
            if(nums[i] == k){
                count++;
            }
            for(int j = i + 1; j < nums.size(); j++){
                // since j is always larger than i, it will cover the case where one element is equal to k 
                if(nums[j] - nums[i] == k){
                    count++;
                }
            }
        }
        
        return count;
    }
};
