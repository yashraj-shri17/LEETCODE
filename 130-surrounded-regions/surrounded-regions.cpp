class Solution {
public:
    vector<pair<int,int>>directions = {
        {-1,0},{1,0},{0,1},{0,-1}
    };
    void dfs(int row , int col , vector<vector<char>>& board){
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || board[row][col]!='O' ) return;
        board[row][col]='z';

        for(int i = 0 ; i < 4 ; i++){
            int crow = row + directions[i].first;
            int ccol = col + directions[i].second;
            dfs(crow , ccol , board);
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<pair<int,int>>border_zeroes;
        int n = board.size();
        int m = board[0].size();
        for(int row = 0 ; row<n ; row++){
            if(board[row][0]=='O')border_zeroes.push_back({row,0});
            if(board[row][m-1]=='O')border_zeroes.push_back({row,m-1});
        }
        for(int col=1 ; col<m-1 ; col++){
            if(board[0][col]=='O')border_zeroes.push_back({0,col});
            if(board[n-1][col]=='O')border_zeroes.push_back({n-1,col});
        }
        for(int i = 0 ; i < border_zeroes.size() ; i++){
            int row = border_zeroes[i].first;
            int col = border_zeroes[i].second;
            dfs(row,col,board);
        }
        for(int i = 0 ; i < n ; i++){
            for(int j=0 ; j < m ; j++){
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='z')board[i][j]='O';
            }
        }
    }
};