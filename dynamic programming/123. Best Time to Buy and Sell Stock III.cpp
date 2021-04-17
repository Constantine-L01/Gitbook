You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[2][4] = { -prices[0], 0, -prices[0], 0};                
 
        for(int i = 1; i < prices.size(); i++){
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[i % 2][0] + prices[i]);
            dp[i % 2][2] = max(dp[(i - 1) % 2][2], dp[i % 2][1] - prices[i]);
            dp[i % 2][3] = max(dp[(i - 1) % 2][3], dp[i % 2][2] + prices[i]);
        }
        
        return dp[(prices.size() - 1) % 2][3];
    }
};
