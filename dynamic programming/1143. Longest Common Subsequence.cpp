Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

If there is no common subsequence, return 0.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // will automatically initiate whole table to be 0
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));
        
        for(int i = 1; i <= text1.size(); i++) {
            for(int j = 1; j <= text2.size(); j++) {
                // if last character matches then increment count by 1
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                // get the max of left subtree or right subtree
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
