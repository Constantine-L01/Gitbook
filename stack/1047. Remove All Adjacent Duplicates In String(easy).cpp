Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

Example 1:

Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

// Stack Solution
class Solution {
public:
    string removeDuplicates(string S) {
        stack<int> st;
    
        for(char s: S) {
            if(st.empty() || st.top() != s){
                st.push(s);
            }
            else {
                st.pop();
            }
        }
        
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

// Two pointers 
class Solution {
public:
    string removeDuplicates(string S) {
        int i = 0, n = S.size();
        
        for(int j = 0; j < n; j++, i++){
            S[i] = S[j];
            // cannot check for i >= 0 , otherwise S[i - 1] will be out of boundary
            if(i > 0 && S[i - 1] == S[i]){
                i -= 2;
            }
        }
        
        return S.substr(0, i);
    }
};




