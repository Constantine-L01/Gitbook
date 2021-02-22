Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf(). 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

// Brute force
class Solution {
public:   
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        
        // only need to go until m - n 
        for(int i = 0; i <= m - n; i++) {
            int j = 0;
            for(; j < n; j++) {
                if(haystack[i + j] != needle[j]) {
                    break;
                }                
            }
            if(j == n) {
                    return i;
                }
        }
        return -1;                  
    }
};
    
// KMP
class Solution {
public:
    void getNext(int* next, const string& s){
        int j = 0;
        next[0] = j;
        // i should start at 1 because i represent the suffix
        for(int i = 1; i < s.size(); i++) {
            // cannot compare when j == 0 and could not move the prefix more ahead since it is the first element
            while(j >= 1 && s[i] != s[j]) {
                // by setting j - 1, infinite loop could be prevent as it will keep moving ahead.
                j = next[j - 1];
            }
            // if both equal then move j and i one step backward.
            if (s[i] == s[j]) {
                j++;
            }
            // the value at i will equal to the length of prefix 
            next[i] = j;
        }
    }
    
    int strStr(string haystack, string needle) {
        // return if no needle
        if(needle.size() == 0){
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for(int i = 0; i < haystack.size(); i++) {
            // if not equal then move j to the element one step behind the prefix 
            // keep moving back if still not equal
            while(j >= 1 && haystack[i] != needle[j]){
                j = next[j-1];
            }
            // move j one step forward if equal
            if(haystack[i] == needle[j]){
                j++;
            }
            // j == needle.size() because if last element match then j will increase by one
            if(j == needle.size()) {
                // need to + 1 because i start from 0 and needle.size() start from 1
                // e.g. size of haystack is 10, i = 9 means found at last element, size of needle is 9, thus need to + 1 
                return (i - needle.size() + 1);
            }
        }
        return -1;              
    }
};
