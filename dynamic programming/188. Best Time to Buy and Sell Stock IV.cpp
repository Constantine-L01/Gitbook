You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again). 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
  
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {        
        if(prices.size() == 0){
            return 0;
        }
        
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        
        for(int i = 1; i < 2 * k; i += 2){
            dp[0][i] = -prices[0];
        }
        
        for(int i = 1; i < prices.size(); i++){
            for(int j = 0; j < 2 * k - 1; j += 2){
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }
        
        return dp[prices.size() - 1][2 * k];
    }
};
