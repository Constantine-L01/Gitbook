Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

class Solution {
public:
    void reverseString(vector<char>& s) {
        // s.size()/2 is correct. case 1(size of even number): swap left and right without middle element exist. case 2(size of odd number): middle element untouched. 
        for(int i = 0, j = s.size()-1; i < s.size()/2; i++, j--){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        return ;
    }
};
