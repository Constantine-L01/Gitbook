You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin. 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
  
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                if(dp[j - coins[i]] != INT_MAX){
                    // no sorting so a smaller coin at later iteration will cost more moves
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
                }
            }
        }
        
        if(dp[amount] != INT_MAX){
            return dp[amount]; 
        } 
        else {
            return -1;
        }
    }
};
