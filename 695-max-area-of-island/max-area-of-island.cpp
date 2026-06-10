class Solution {
public:
    int n,m;
    void dfs(int i , int j , vector<vector<int>>& grid,int &temp){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0) return;
        temp++;
        grid[i][j]=0;
        dfs(i,j+1,grid,temp);
        dfs(i,j-1,grid,temp);
        dfs(i+1,j,grid,temp);
        dfs(i-1,j,grid,temp);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxArea  = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]==1){
                    int temp = 0;
                    dfs(i,j,grid,temp);
                    maxArea = max(maxArea,temp);
                }
            }
        }
        if(maxArea==INT_MIN) return 0;
        return maxArea;
    }
};