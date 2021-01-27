Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

class Solution {
public:
    const string letterMap[10] = {
        "", //0
        "", //1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9        
    };
    
    vector<string> result;
    string s;
    
    void backtracking(const string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }
        // change from char to int
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        
        // every time need to check all the letter of the respective digit
        for(int i = 0; i < letters.size(); i++){
            s.push_back(letters[i]);
            // index + 1 is to go to next digit
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};
