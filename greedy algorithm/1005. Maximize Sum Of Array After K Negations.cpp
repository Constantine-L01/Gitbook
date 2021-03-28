Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we repeat this process K times in total.  (We may choose the same index i multiple times.)

Return the largest possible sum of the array after modifying it in this way. 

Example 1:

Input: A = [4,2,3], K = 1
Output: 5
Explanation: Choose indices (1,) and A becomes [4,-2,3].
  
class Solution {
public:
    static bool cmp(int a, int b){
        return abs(a) > abs(b);
    }
    
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);
        for(int i = 0; i < A.size(); i++){
            if(A[i] < 0 && K > 0){
                A[i] *= -1;
                K--;
            }
        }
        
        while(K--) {
            A[A.size() - 1] *= -1;
        }
        
        int sum = 0;
        for(auto a: A){
            sum += a;
        }
        
        return sum;
    }
};
