class Solution {
public:
    vector<vector<int>>dir = {{-1,0},{1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>queue;
        int fo = 0;
        // got number of fresh oranges and bfs queue
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j]==1) fo++;
                if(grid[i][j]==2) queue.push({i,j});
            }
        }
        
        int ans = 0;
        queue.push({-1,-1});
        while(queue.size()>0){
            auto ele = queue.front();
            queue.pop();
            int row = ele.first;
            int col = ele.second;
            if(row==-1 and col==-1){
                ans++;
                if(queue.size()==0) break;
                else queue.push({-1,-1});
            }else{
                for(int d = 0 ; d < 4 ; d++){
                int nr = row + dir[d][0];
                int nc = col + dir[d][1];
                if(nr<0 || nr >= grid.size() || nc<0 || nc>=grid[0].size()) continue;
                if(grid[nr][nc]==0) continue;
                if(grid[nr][nc]==2) continue;
                queue.push({nr,nc});
                fo--;
                grid[nr][nc]=2;
            }
            }
        }
        if (fo > 0) return -1;
        return ans - 1;
    }
};