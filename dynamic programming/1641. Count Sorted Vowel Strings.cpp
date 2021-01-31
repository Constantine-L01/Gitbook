Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].

// with n=2, aa ae ai ao au ee ei eo eu ii io iu oo ou uu = 5 + 4 + 3 + 2 + 1
// {1,1,1,1,1} => n=1 {1,2,3,4,5} => n=2 {1,3,6,10,15}
class Solution {
public:
    int countVowelStrings(int n) {
        int dp[5] = {1,1,1,1,1};
        // i is the iterations of the update of the table 
        for(int i = 0; i < n; i++){
            // j is for the alphabet
            for(int j = 1; j < 5; j++){
                dp[j] = dp[j] + dp[j-1]; 
            }
        }
        return dp[4];
    }
};
