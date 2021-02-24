Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Example 1:

Input: s = "()"
Output: true

Example 4:

Input: s = "([)]"
Output: false

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') {
                st.push(')');
            }
            else if(s[i] == '[') {
                st.push(']');
            }
            else if(s[i] == '{') {
                st.push('}');
            }
            else if(st.empty() || s[i] != st.top()){
                return false;
            }
            else{
                st.pop();
            }
        }
        return st.empty();
    }
};
