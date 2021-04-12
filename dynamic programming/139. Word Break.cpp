Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation. 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
  
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        
        dp[0] = true;
        
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                // will substring till the last character since i == s.size() and substr function take [pos, pos + len)
                // i.e. size == 7, pos == 4, get 4,5,6
                string word = s.substr(j, i - j);
                if(wordSet.find(word) != wordSet.end() && dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.size()];
    }
};
  
