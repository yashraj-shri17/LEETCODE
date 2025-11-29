class Solution {
public:
    vector<int>parents, Rank;
    struct Edge{
        int a ,b ,val;
    };
    vector<Edge> coord_connect;
    int findp(int child){
        if(parents[child]==child) return child;
        return parents[child] = findp(parents[child]);
    }
    bool unite(int x , int y){
        int a = findp(x) , b = findp(y);
        if(a!=b){
            if(Rank[a]<Rank[b]) swap(a,b);
            parents[b] = a;
            if(Rank[a]==Rank[b]) Rank[a]++;
            return true;   // RETURN TRUE when union successful
        }
        return false;      // CYCLE
    }
    int kruskals(){
        sort(coord_connect.begin(), coord_connect.end(),
         [](const Edge &x, const Edge &y){
             return x.val < y.val;
         });
        int minCost = 0;
        for(int i = 0; i < coord_connect.size(); i++){
            Edge curr = coord_connect[i];
            if(unite(curr.a, curr.b)) minCost += curr.val; // if merged successfully
        }
        return minCost;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parents.resize(n);
        Rank.resize(n,0);
        for(int i = 0; i < n; i++) parents[i] = i;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                coord_connect.push_back({i, j,
                    abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])
                });
            }
        }
        return kruskals();
    }
};
