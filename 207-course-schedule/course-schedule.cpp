class Solution {
public:
    vector<list<int>>graph;
    int total_can_complete = 0;
    int n;
    void add_edge(int from , int to , bool bi_dir = true){
        graph[from].push_back(to);
        if(bi_dir) graph[to].push_back(from);
    }
    void kahns_algo(){
        vector<int>indegree(n,0);
        for(int i = 0 ; i < n ; i++){
            for(auto neighbours : graph[i]){
                indegree[neighbours]++;
            }
        }
        queue<int>qu;
        unordered_set<int>vis;
        for(int i = 0 ; i < n ; i++){
            if(indegree[i]==0){
                qu.push(i);
                vis.insert(i);
            }
        }
        while(qu.size()>0){
            int front = qu.front();
            total_can_complete++;
            qu.pop();
            for(auto neighbour : graph[front]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    qu.push(neighbour);
                    vis.insert(neighbour);
                }
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        n = numCourses;
        graph.resize(n,list<int>());
        for(int i = 0 ; i < prereq.size() ; i++){
            int from = prereq[i][1];
            int to = prereq[i][0];
            add_edge(from , to , false);
        }
        kahns_algo();
        return total_can_complete == numCourses;
    }
};
