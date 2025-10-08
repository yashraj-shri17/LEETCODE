class Solution {
public:
    // Check if it's safe to place a queen at (row, col)
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int r = row, c = col;

        // Check upper-left diagonal
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--; c--;
        }

        // Check lower-left diagonal
        r = row; c = col;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r++; c--;
        }

        // Check left row
        r = row; c = col;
        while (c >= 0) {
            if (board[r][c] == 'Q') return false;
            c--;
        }

        return true;
    }

    // Backtracking function
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    // Main function
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.')); // initialize n x n board
        solve(0, board, ans, n);
        return ans;
    }
};
