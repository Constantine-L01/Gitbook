Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false

// array
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        
        for(int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        
        for(int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        
        for(int i = 0; i < 26; i++){
            if(record[i] != 0){
                return false;
            }
        }        
        return true;
    }
};

// unordered_map
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> record;
        
        for(int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        
        for(int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        
        for(auto r: record){
            if(r.second != 0){
                return false;
            }
        }    
        return true;
    }
};
