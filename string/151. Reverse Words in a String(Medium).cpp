Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces. 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"

class Solution {
public:
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    
    void removeExtraSpaces(string& s){
        int slowIndex = 0, fastIndex = 0;
        while(s[fastIndex] == ' '){
            fastIndex++;
        }
        
        for(; fastIndex < s.size(); fastIndex++) {
            // will always preserve the first ' '
            if(fastIndex - 1 > 0 && (s[fastIndex - 1] == s[fastIndex]) && s[fastIndex] == ' ' ){
                continue;
            }
            else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        
        // need to - 1 because slowIndex has increased by one even if fastIndex == s.size()
        // if last element is ' ' then take all the element before the last element
        // otherwise, take all the element
        if(slowIndex - 1 > 0 && s[slowIndex - 1] == ' '){
            s.resize(slowIndex - 1);
        }
        else {
            s.resize(slowIndex);
        }
        return;
    }
    
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.length() - 1);
        int start = 0, end = 0;
        bool entry = false;
        
        for(int i = 0; i < s.length(); i++) {
            // will always land in word since there is only one ' ' between words
            if(!entry) {
                start = i;
                entry = true;
            }
            
            // all words except the last word
            if(entry && s[i] == ' ' && s[i - 1] != ' ') {
                end = i - 1;
                reverse(s, start, end);
                entry = false;
            }
            
            // case of last word
            if(entry && (i == (s.length() - 1)) && s[i] != ' ') {
                end = i;
                reverse(s, start, end);
                entry = false;
            }
        }        
        return s;
    }
};
