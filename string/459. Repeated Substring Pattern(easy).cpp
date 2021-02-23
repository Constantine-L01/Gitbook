Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

Example 2:

Input: s = "aba"
Output: false

// s + s solution
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2*s.size() - 2).find(s) != -1;
    }
};

// brute force
class Solution {
public:
    bool isCopies(string s, string subStr){
        if(s.size() % subStr.size() != 0){
            return false;
        }
        
        // will check through whole string to ensure there is no non-repeated area
        for(int i = subStr.size(); i < s.size(); i += subStr.size()){
            if(s.substr(i, subStr.size()) != subStr){
                return false;
            }
        }
        return true;
    }
    
    bool repeatedSubstringPattern(string s) {
        int sSize = s.size();
        if(sSize == 1) {
            return false;
        }
        
        char first = s[0];
        string subStr;
        subStr+= first;
        
        // i <= sSize/2 because it cant have repeated substring if prefix is larger than half the string
        for(int i = 1; i <= sSize/2; i++) {
            if(first == s[i] && isCopies(s, subStr)) {
                return true;
            }
            // if repeated substring require more char
            else {
                subStr+= s[i];
            }
        }        
        return false;
    }
};
