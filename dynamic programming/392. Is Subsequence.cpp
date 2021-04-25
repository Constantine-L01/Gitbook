Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true

class Solution {
public:  
  bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        // need to + 1 because 0 index will be used to indicate empty string
        int dp[m + 1][n + 1];
        
        // the length of subsequence will be 0 if either string is empty
        for(int i = 0; i <= m; i++){
            dp[i][0] = 0;
        }
        
        for(int j = 0; j <= n; j++){
            dp[0][j] = 0;
        }
        
        // use i-1 and j-1 because indexes start at 1
        // if last position of both strings match, then increment length by one, otherwise assign the current matched length to dp[i][j]
        // bottom-up approach, starting from matching of the first character of both string, then populate the table        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == t[j-1]){
                    // at here will increment correctly in the case of 'aa' and 'aaaaaa' since only first character of string s will be considered when i=1, first 2 character will be considered when i=2  
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        
        if(dp[m][n] == s.size()){
            return true;
        }
        else return false;
    }
};

// reverse traversal, actually its not, need to think again
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, 0));
        for (int i = 1; i <= t.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (s[j - 1] == t[i - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = dp[i - 1][j];
            }
        }
        if (dp[t.size()][s.size()] == s.size()) return true;
        return false;
    }
};


