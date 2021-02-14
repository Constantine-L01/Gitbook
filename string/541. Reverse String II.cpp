Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

Example:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"

class Solution {
public:
    
    void reverse(string& s, int start, int end){
        // end - start + 1 is the same as s.size()
        int offset = (end - start + 1) / 2;
        for(int i = start, j = end; i < start + offset; i++, j--){
            swap(s[i], s[j]);
        }
        return;
    }
    
    string reverseStr(string s, int k) {
        // increase i by 2k
        // will end at 2 cases. 
        // 1) less than k characters after i
        // 2) i + k <= s.size(), thus there will be no next iteration and the remaining s.size() - (i + k) characters will remain unreversed
        for(int i = 0; i < s.size(); i += (2 * k)){
            // if remaining char is more than or equal to k, then reverse first k characters
            if(i + k <= s.size()){
                reverse(s, i, i + k - 1);                
            }
            // otherwise reverse all the remaining characters
            else {
                reverse(s, i, s.size() - 1);
            }
        }
        
        return s;
    }
};
