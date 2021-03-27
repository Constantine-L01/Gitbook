Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
  
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) {
            return 0;
        }
        
        int currDistance = 0;
        int ans = 0;
        int nextDistance = 0;
        
        for(int i = 0; i < nums.size(); i++){
            nextDistance = max(i + nums[i], nextDistance);
            if(i == currDistance){
                if(currDistance != nums.size() - 1){
                    ans++;
                    currDistance = nextDistance;
                    if(nextDistance >= nums.size() - 1){
                        break;
                    }
                }
                // because it will break when nextDistance >= nums.size() - 1, thus currDistance will only be equal to or smaller than nums.size() - 1, and in the case of equal to,             the for loop will end at next iteration, thus no need for else break 
                // else break;
            }
        }
        
        return ans;
    }
};

// simplified solution, because the question assume that the last index could always be reach, so just +1 if currDistance could only reach the last 2nd element. 
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) {
            return 0;
        }
        
        int currDistance = 0;
        int ans = 0;
        int nextDistance = 0;
        
        for(int i = 0; i < nums.size() - 1; i++){
            nextDistance = max(i + nums[i], nextDistance);
            if(i == currDistance){
               ans++;
                currDistance = nextDistance;
            }
        }
        
        return ans;
    }
};



