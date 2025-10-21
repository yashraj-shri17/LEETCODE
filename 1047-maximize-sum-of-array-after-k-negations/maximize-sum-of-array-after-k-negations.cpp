class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
       // solving with greedy algorithm 
       priority_queue<int,vector<int>,greater<int>>min_heap(nums.begin(),nums.end());
       while(k--){
        int top = min_heap.top();
        min_heap.pop();
        min_heap.push(-top);
       } 
       int sum = 0;
       while(min_heap.size()>0){
        sum+=min_heap.top();
        min_heap.pop();
       }
       return sum;
    }
};