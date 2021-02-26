Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.
  
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
  
// two pointers
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int i = 0, n = s.size();
        vector<int> count(n);
        for(int j = 0; j < n; j++, i++){
            s[i] = s[j];
            if(i > 0 && s[i] == s[i - 1]){
                count[i] = count[i - 1] + 1;
            }
            else {
                count[i] = 1;
            }
            if(count[i] == k){
                i -= k;
            }
        }
        
        return s.substr(0, i);
    }
};

// Stack
class Solution {
public:
    string removeDuplicates(string s, int k) {
        // could place a placeholder, then no need to check for st.empty()
        vector<pair<int, char>> st ;
        
       for(char c: s){
           if(!st.empty() && st.back().second != c){
               st.push_back({1, c});
           }
           else if(!st.empty() && ++st.back().first == k) {
               st.pop_back();
           }
           else if(st.empty()) {
               st.push_back({1, c});
           }
       }
        
        string res;
        for(auto & p: st){
            res.append(p.first, p.second);
        }
        
        return res;
    }
};
