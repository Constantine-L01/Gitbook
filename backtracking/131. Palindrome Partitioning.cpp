Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward. 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    
    void backtracking(const string& s, int startIndex){
        // but will equal to s.size() after enter the bactracking function of last iteration of each loop.
        if(startIndex >= s.size()){
            res.push_back(path);
            return;
        }
        
        // i will not equal to s.size() in this for loop
        for(int i = startIndex; i < s.size(); i++){
            if(isPalindrome(s, startIndex, i)){
                // need to +1 because need to take first element when i == startIndex
                path.push_back(s.substr(startIndex, i - startIndex + 1));                
            }
            else {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    
    bool isPalindrome(const string& s, int start, int end){
        for(int i = start, j = end; i < j; i++, j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
};
