class Solution {
public:
    typedef pair<int,vector<int>> pi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi>pq;
        for(int i = 0 ; i < points.size() ; i++){
            vector<int>coord;
            coord.push_back(points[i][0]);
            coord.push_back(points[i][1]);
            pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],coord});

            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>>ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};