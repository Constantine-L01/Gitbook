Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

class Solution {
public:
    vector<string> res;
    int pointNumber = 0;
    
    void backtracking(string& s, int startIndex){
        if(pointNumber == 3){
            if(isValid(s, startIndex, s.size() - 1)){
                res.push_back(s);                
            }
            // return must be at here
            return;
        }        
        
        for(int i = startIndex; i < s.size(); i++){
            if(isValid(s, startIndex, i)){
                // need to + 1 i.e. startIndex == 0, thus i == 0 and s.begin() == 0, but still need to take first element
                s.insert(s.begin() + i + 1, '.');
                pointNumber++;
                backtracking(s, i + 2);
                pointNumber--;
                s.erase(s.begin() + i + 1);
            }
            else {
                break;
            }
        }
    }
    
    bool isValid(const string& s, int start, int end){
        // need to check whether start is larger than end because i + 2 at backtracking
        if(start > end){
            return false;
        }
        
        if(s[start] == '0' && start != end){
            return false;
        }
        
        int num = 0;
        for(int i = start; i <= end; i++){
            if(s[i] > '9' || s[i] < '0'){
                return false;
            }
            num = num* 10 + (s[i] - '0');
            if(num > 255){
                return false;
            }
        }
        return true;
    }
    
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0);
        return res;
    }
};
