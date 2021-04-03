You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again). 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
  
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int result = 0;
        int minPrice = prices[0];
        
        for(int i = 0; i < prices.size(); i++){
            // minPrice is always minPrice - fee, thus if current stock price is lower than the minPrice with transaction fee attached,
            // it means that we should buy the current stock because it could produce more profits when sold. 
            // it means that 2nd if statement will be false if 1st if statement is true
            // 3rd if statement will be always be true if 1st statement is false
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            }
            
            // will continue if prices[i] < minPrice valid for this iteration since there is no point to deduct itself, prices[i] == minPrice, thus prices[i] <= minPrice + fee is true
            // at here, minPrice equal to minPrice - fee after first iteration of minPrice = prices[0], 
            // thus prices[i] + fee >= minPrice + fee checks for buying, if prices[i] + fee is greater than true minPrice, then should just hold on minPrice.
            // prices[i] <= minPrice + fee can coverts into prices[i] - fee <= minPrice, means that if the value of prices[i] - fee is lower than holding price, 
            // then selling will results in negative earning. 
            if(prices[i] >= minPrice && prices[i] <= minPrice + fee){
                continue;
            }
            
            // at here minPrice is without transaction fee attached. 
            if(prices[i] > minPrice){
                result += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee;
            }
        }
        
        return result;
    }
};

// another similar solution
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int result = 0;
        int minPrice = prices[0];
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            }
            
            // more but not that more i.e. [5, 4], fee = 2
            // 1st if statement will be false because 4 > 5 - 2, thus 2nd if statement check whether current price is between 3 and 5
            // does not consider about buying, just don't sell because the current price is lower than the original minPrice.
            // prices[i] >= minPrice &&  is not needed since it will be true if 1st statement is false
            // then 2nd statement is to check whether the current price is more than original buying price.
            // if it is more then add the difference to result, otherwise continue
            if(prices[i] <= minPrice + fee){
                continue;
            }            
            
            result += prices[i] - minPrice - fee;
            minPrice = prices[i] - fee;
            
        }
        
        return result;
    }
};
