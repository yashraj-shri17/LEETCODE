class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return;
        int m = board[0].size();
        queue<pair<int,int>> q;
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') { board[0][j] = '-'; q.push({0,j}); }
            if(board[n-1][j] == 'O') { board[n-1][j] = '-'; q.push({n-1,j}); }
        }
        for(int i = 1; i < n-1; i++) {
            if(board[i][0] == 'O') { board[i][0] = '-'; q.push({i,0}); }
            if(board[i][m-1] == 'O') { board[i][m-1] = '-'; q.push({i,m-1}); }
        }
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for(auto d : dir) {
                int nr = r + d[0], nc = c + d[1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='O') {
                    board[nr][nc] = '-';
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='-') board[i][j]='O';
            }
        }
    }
};
