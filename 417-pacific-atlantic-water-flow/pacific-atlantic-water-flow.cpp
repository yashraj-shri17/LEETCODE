class Solution {
public:
    int row;
    int col;
    vector<vector<int>> grid;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       row = heights.size();
       col = heights[0].size();
       grid = heights ;
       queue<pair<int,int>>qu_pacific;
       queue<pair<int,int>>qu_atlantic;
       // pushing col->0 and col->last in pacific and atlantic
       for(int i = 0 ; i < row ; i++){
        qu_pacific.push({i,0});
        qu_atlantic.push({i,col-1});
       }
       for(int j = 1 ; j < col ; j++){
        qu_pacific.push({0,j});
       }
       for(int j = 0 ; j < col-1 ; j++){
        qu_atlantic.push({row-1,j});
       }
       vector<vector<bool>>pacificbfs; // areas where pacific water can reach
       pacificbfs = bfs(qu_pacific);
       vector<vector<bool>>atlanticbfs; // areas where atlantic water can reach
       atlanticbfs = bfs(qu_atlantic);
       vector<vector<int>>answer;
       for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            if(atlanticbfs[i][j] && pacificbfs[i][j]) answer.push_back({i,j});
        }
       }
       return answer;
    }
    vector<vector<bool>> bfs(queue<pair<int,int>>& queue){
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        while(queue.size()>0){
            auto front = queue.front();
            queue.pop();
            int front_row = front.first;
            int front_col = front.second;
            visited[front_row][front_col] = true;
            // now iterate on all four direction ;
            for(int d = 0 ; d < 4 ; d++){
                int nr = front_row + dir[d][0];
                int nc = front_col + dir[d][1];
                if(nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
                if(visited[nr][nc]==true) continue;
                if(grid[nr][nc] < grid[front_row][front_col]) continue;
                visited[nr][nc] = true;
                queue.push({nr,nc});
            }
        }
        return visited;
    }
};