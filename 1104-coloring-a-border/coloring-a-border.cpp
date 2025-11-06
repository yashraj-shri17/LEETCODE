class Solution {
public:
    void dfs(vector<vector<int>>& grid , int currRow , int currCol , int actual_color , vector<pair<int,int>>& boundary_cells , vector<vector<int>>& visited){
        int n = grid.size();
        int m = grid[0].size();
        if(currRow<0 || currCol<0 || currRow>=n || currCol>=m || grid[currRow][currCol]!=actual_color || visited[currRow][currCol]) return;
        visited[currRow][currCol] = 1;
        if(currRow == 0 || currRow==n-1 || currCol==0 || currCol==m-1 ||
           grid[currRow][currCol]!=grid[currRow+1][currCol] ||
           grid[currRow][currCol]!=grid[currRow-1][currCol] ||
           grid[currRow][currCol]!=grid[currRow][currCol+1] ||
           grid[currRow][currCol]!=grid[currRow][currCol-1]){
            boundary_cells.push_back({currRow , currCol});
        }
        dfs(grid , currRow+1 , currCol , actual_color , boundary_cells , visited);
        dfs(grid , currRow-1 , currCol , actual_color , boundary_cells , visited);
        dfs(grid , currRow , currCol-1 , actual_color , boundary_cells , visited);
        dfs(grid , currRow , currCol+1 , actual_color , boundary_cells , visited);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        if(grid[row][col]==color) return grid;
        vector<pair<int,int>> boundary_cells;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        dfs(grid , row , col, grid[row][col] , boundary_cells , visited);
        for(int i = 0 ; i < boundary_cells.size() ; i++) grid[boundary_cells[i].first][boundary_cells[i].second] = color;
        return grid; 
    }
};
