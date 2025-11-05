class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>visited;
        queue<int>qu;
        visited.insert(0);
        qu.push(0);
        while(qu.size()>0){
            int front = qu.front();
            qu.pop();
            for(auto neighbours : rooms[front]){
                if(!visited.count(neighbours)){
                    visited.insert(neighbours);
                    qu.push(neighbours);
                }
            }
        }
        return visited.size() == rooms.size() ;
    }
};