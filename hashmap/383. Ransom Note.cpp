Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note. 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

// greedy algorithm
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for(int i = 0; i < magazine.length(); i++) {
            for(int j = 0; j < ransomNote.length(); j++) {
                if(ransomNote[j] == magazine[i]){
                    ransomNote.erase(ransomNote.begin() + j);
                    break;
                }
            }
        }
        
        if(ransomNote.length() == 0){
            return true;
        }
        
        return false;
    }
};

// O(m+n)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26] = {0};
        
        for(int i = 0; i < magazine.length(); i++) {
            arr[magazine[i] - 'a']++;
        }
        
        for(int i = 0; i < ransomNote.length(); i++) {
            arr[ransomNote[i] - 'a']--;
            
            if(arr[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
};
