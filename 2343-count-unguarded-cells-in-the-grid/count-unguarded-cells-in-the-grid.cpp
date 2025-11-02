class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m, vector<int>(n, 1)); // initialize all to 1
        
        // Mark guards
        for (auto &g : guards)
            matrix[g[0]][g[1]] = 10;
        
        // Mark walls
        for (auto &w : walls)
            matrix[w[0]][w[1]] = 20;
        
        // Directions: up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        for (auto &g : guards) {
            int x = g[0], y = g[1];
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                while (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (matrix[nx][ny] == 10 || matrix[nx][ny] == 20) break; // stop if guard or wall
                    if (matrix[nx][ny] == 1) matrix[nx][ny] = 200; // mark guarded
                    nx += dx[d];
                    ny += dy[d];
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 1)
                    ans++;
        
        return ans;
    }
};
