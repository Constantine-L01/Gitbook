Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It is guaranteed the answer fits on a 32-bit signed integer. 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned int>> dp(s.size() + 1, vector<unsigned int>(t.size() + 1));
        for(int i = 0; i <= s.size(); i++){
            dp[i][0] = 1;
        }
        // start j from 1 because dp[0][0] means there 0 character of t is a subsequences of 0 character of s 
        for(int j = 1; j <= t.size(); j++){
            dp[0][j] = 0;
        }
        
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= t.size(); j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[s.size()][t.size()];
    }
};
