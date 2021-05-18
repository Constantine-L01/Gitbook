Given an m x n matrix board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region. 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

class UF {
private: 
    int* parent;
    int* rank;
    int count;
    
public:
    UF(int N)
    {
        count = N;
        parent = new int[N];
        rank = new int[N];
        for (int i = 0; i < N; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    ~UF()
    {
        delete [] parent;
        delete [] rank;
    }
    
    int find(int p){
        while(p != parent[p]){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    
    int getCount() {
        return count;
    }
    
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    
    void connect(int p, int q) {
        int i = find(p);
        int j = find(q);
        if(i == j) {
            return;
        }
        else if(rank[i] < rank[j]){
            parent[i] = j;
            rank[i] += rank[j];
        }
        else{
            parent[j] = i;
            rank[j] += rank[i];
        }
        count--;
    }
};

class Solution {
    public:        
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) {
            return;
        }
        int n = board[0].size();
        UF uf = UF(m*n + 1);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j] == 'O'){
                    uf.connect(i*n+j, m*n);
                }
                else if(board[i][j] == 'O'){
                    if(board[i - 1][j] == 'O'){
                        uf.connect(i*n + j, (i - 1)*n + j);
                    }
                    if(board[i + 1][j] == 'O'){
                        uf.connect(i*n + j, (i + 1)*n + j);
                    }
                    if(board[i][j - 1] == 'O'){
                        uf.connect(i*n + j, i*n + j - 1);
                    }
                    if(board[i][j + 1] == 'O'){
                        uf.connect(i*n + j, i*n + j + 1);
                    }
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!uf.connected(i*n + j, m*n)){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
