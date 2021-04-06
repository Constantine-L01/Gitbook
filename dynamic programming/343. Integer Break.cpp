Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get. 

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
 
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i - 1; j++){
                dp[i] = max(dp[i], max((i - j)*j, dp[i - j]*j));
            }
        }
        
        return dp[n];
    }
};
