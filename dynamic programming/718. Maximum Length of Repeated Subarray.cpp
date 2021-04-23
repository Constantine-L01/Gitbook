Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays. 

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {  
        int n = nums1.size();
        int m = nums2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        int result = 0;                       
                               
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(nums1[i - 1] == nums2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if(dp[i][j] > result){
                    result = dp[i][j];
                }
            }            
        }
                             
        return result;
    }
};
