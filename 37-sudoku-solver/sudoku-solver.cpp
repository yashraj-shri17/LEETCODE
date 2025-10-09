class Solution {
public:
    bool canPlace(vector<vector<char>>& board, int i, int j, int num){
        for(int c = 0; c < 9; c++){
            if(board[i][c] != '.' && board[i][c] - '0' == num) return false;
        }
        for(int r = 0; r < 9; r++){
            if(board[r][j] != '.' && board[r][j] - '0' == num) return false;
        }
        int x = (i/3)*3;
        int y = (j/3)*3;
        for(int r = x; r < x + 3; r++){
            for(int c = y; c < y + 3; c++){
                if(board[r][c] != '.' && board[r][c] - '0' == num) return false;
            }
        }
        return true;
    }

    bool f(vector<vector<char>>& board, int i, int j){
        if(i == 9) return true;
        if(j == 9) return f(board, i + 1, 0);
        if(board[i][j] != '.') return f(board, i, j + 1);

        for(int k = 1; k <= 9; k++){
            if(canPlace(board, i, j, k)){
                board[i][j] = char('0' + k);
                if(f(board, i, j + 1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        f(board, 0, 0);
    }
};
