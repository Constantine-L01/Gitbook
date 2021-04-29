Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size() , false));
        int result = 0;
        
        for(int i = s.size() - 1; i >= 0; i--) {
            for(int j = i; j < s.size(); j++) {
                if(s[i] == s[j]) {
                    if(j - i <= 1) {
                        result++;
                        dp[i][j] = true;
                    }
                    else if(dp[i + 1][j - 1]) {
                        result++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        
        return result;
    }
};
