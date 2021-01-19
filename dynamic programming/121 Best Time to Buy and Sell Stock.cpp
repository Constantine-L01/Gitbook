You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:    
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.    
    
class Solution {
public:
    int max(int a , int b) {
        return a > b ? a : b;
    }
    
    int maxProfit(vector<int>& prices) {
        int maxCur = 0;
        int maxOverall = 0;
        
        //traverse through each price in the array, maxCur will record the current subarray with largest earning, reset to 0 if one price will cause the subarray become -ve, maxOverall
        //will record the highest positive subarray.
        for(int i = 1; i < prices.size(); i++) {
            maxCur = max(maxCur += prices[i] - prices[i - 1], 0);
            maxOverall = max(maxCur, maxOverall);
        }
        
        return maxOverall;
    }
};
