class Solution {
public:
    int max(int a , int b) {
        return a > b ? a : b;
    }
    
    int maxProfit(vector<int>& prices) {
        int maxCur = 0;
        int maxOverall = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            maxCur = max(maxCur += prices[i] - prices[i - 1], 0);
            maxOverall = max(maxCur, maxOverall);
        }
        
        return maxOverall;
    }
};
