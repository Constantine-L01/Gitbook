Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

You may return the answer in any order.

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtracking(int n, int k, int startIndex){
        if(path.size() == k){
            res.push_back(path);
            return;
        }

        for(int i = startIndex; i <= n; i++){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {     
        backtracking(n, k , 1);
        return res;
    }
};

// optimized
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtracking(int n, int k, int startIndex){
        if(path.size() == k){
            res.push_back(path);
            return;
        }
        
        // need to +1 because need to include the first element e.g. n = 4, k = 4 but need to take in 1, then 2, then 3, then 4
        for(int i = startIndex; i <= n - (k - path.size()) + 1; i++){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {     
        backtracking(n, k , 1);
        return res;
    }
};
