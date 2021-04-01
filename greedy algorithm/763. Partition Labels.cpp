A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts. 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

class Solution {
public:
    vector<int> partitionLabels(string S) {
       int hash[26] = {0};
        
        for(int i = 0; i < S.size(); i++){
            hash[S[i] - 'a'] = i;
        }
        
        vector<int> result;
        int left = 0, right = 0;        
        
        for(int i = 0; i < S.size(); i++){
            right = max(right, hash[S[i] - 'a']);
            if(i == right){
                result.push_back(right - left + 1);
                left = right + 1;
            }
        }
        
        return result;
    }
};
