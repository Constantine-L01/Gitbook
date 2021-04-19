You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

    After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];
        
        for(int i = 1; i < prices.size(); i++){
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2]);
        }
        
        return max({ dp[prices.size() - 1][1], dp[prices.size() - 1][2], dp[prices.size() - 1][3] });
    }
};
