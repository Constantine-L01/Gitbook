Given a string s, find the length of the longest substring without repeating characters. 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int result = 0;
        
        unordered_set<char> set;
        
        while(j < s.size()){
            if(set.find(s[j]) == set.end()){
                set.insert(s[j]);
                j++;
                // i.e. i = 0, j = 0, then need to + 1, can think as deduction of i from j will exclude ith element, and thus need to + 1 to account ith element.
                result = max(result, j - i);
            }
            else {
                set.erase(s[i]);
                i++;
            }
        }
        
        return result;
    }
};
