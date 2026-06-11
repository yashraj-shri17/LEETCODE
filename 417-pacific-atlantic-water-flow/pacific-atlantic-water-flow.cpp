class Solution {
public:
    vector<pair<int,int>>directions = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };
    vector<vector<int>>copy;
    void bfs(int row , int col , vector<vector<bool>> &grid ){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]==true) return;
        grid[row][col] = true;
        for(int i=0;i<directions.size();i++){
            int c_row = row+directions[i].first;
            int c_col = col+directions[i].second;
            if( c_row<0 || c_row>=grid.size() || c_col<0 || c_col>=grid[0].size() || copy[c_row][c_col]>=copy[row][col])bfs(c_row,c_col,grid);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
     int n = heights.size();
     int m = heights[0].size();
     copy = heights;

    //initalisting required things
     vector<vector<bool>> pacific(n, vector<bool>(m, false));
     vector<vector<bool>> atlantic(n, vector<bool>(m, false));
     vector<pair<int, int>> pa_border;
     vector<pair<int, int>> at_border;


    //adding border elements
    for(int col = 0 ; col < m ; col++){
        pa_border.push_back({0,col});
        at_border.push_back({n-1,col});
    }
    for(int row = 1 ; row < n-1 ; row++){
        pa_border.push_back({row,0});
        at_border.push_back({row,m-1});
    }
    at_border.push_back({0,m-1});
    pa_border.push_back({n-1,0});
    for(auto x : pa_border){
        cout<<x.first<<" "<<x.second<<"\n";
    }
    cout<<"\n";
    for(auto x : at_border){
        cout<<x.first<<" "<<x.second<<"\n";
    }
    for(int i = 0 ; i < pa_border.size() ; i++){
        int r_no = pa_border[i].first;
        int c_no = pa_border[i].second;
        if(pacific[r_no][c_no]==false) bfs(r_no , c_no , pacific);
    }

    for(int i = 0 ; i < at_border.size() ; i++){
        int r_no = at_border[i].first;
        int c_no = at_border[i].second;
        if(atlantic[r_no][c_no]==false) bfs(r_no , c_no , atlantic);
    }

    vector<vector<int>>ans;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m  ; j++){
            if(atlantic[i][j] && pacific[i][j]) ans.push_back({i,j});
        }
    }

    return ans;
    }
};