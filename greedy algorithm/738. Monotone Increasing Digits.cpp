 Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example 1:

Input: N = 10
Output: 9

Example 2:

Input: N = 1234
Output: 1234
  
// time limit exceeded
class Solution {
public:
    bool checkSum(int N){
        int currMax = 10;
        while(N){
            int k = N % 10;
            if(currMax >= k){
                currMax = k;
            }
            else return false;
            N = N / 10;
        }
        
        return true;
    }
    
    int monotoneIncreasingDigits(int N) {
        for(int i = N; i >= 0; i--){
            if(checkSum(i)){
                return i;
            }
        }
        return 0;
    }
};
