class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto x: stones) pq.push(x);
        int k=2;
        while(pq.size()>1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(x==y) continue;
            pq.push(y-x);
        }
        if(pq.size()==0) return 0;
        return pq.top();
    }
};