Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        
        for(string s: strs){
            string t = s;
            sort(t.begin(), t.end());
            map[t].push_back(s);
        }
        
        vector<vector<string>> ret;
        
        for(pair<string, vector<string>> mp: map){
            ret.push_back(mp.second);
        }
        
        return ret;
    }
};
