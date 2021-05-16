The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

    For example, "ACGAATTCCG" is a DNA sequence.

When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order. 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<int> first;
        unordered_set<int> sec;
        vector<string> res;
        int n = s.size();
        
        int map[26];
        map['A' - 'A'] = 0;
        map['C' - 'A'] = 1;
        map['G' - 'A'] = 2;
        map['T' - 'A'] = 3;
        
        int val = 0;
        for(int i = 0; i < 10 && i < s.size(); i++){           
            val <<= 2;
            val |= map[s[i] - 'A'];
        }
        first.insert(val);

        // cannot directly use s.size(), otherwise, overflow
        for(int i = 1; i < n - 9; i++){
            val &= ~(3 << 18);
            val = val << 2;
            val = val | map[s[i + 9] - 'A'];
            if(first.find(val) == first.end()){
                first.insert(val);
            }
            else if(sec.find(val) == sec.end()){
                sec.insert(val);
                res.push_back(s.substr(i, 10));
            }
        }
        
        return res;
    }
};
