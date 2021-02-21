Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf(). 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

// KMP
class Solution {
public:
    void getNext(int* next, const string& s){
        int j = 0;
        next[0] = j;
        for(int i = 1; i < s.size(); i++) {
            while(j >= 1 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for(int i = 0; i < haystack.size(); i++) {
            while(j >= 1 && haystack[i] != needle[j]){
                j = next[j-1];
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == (needle.size() )) {
                return (i - needle.size() + 1);
            }
        }
        return -1;              
    }
};
