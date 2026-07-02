class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto x : nums){
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }   
        return pq.top(); 
    }
};

// // 1 2 2 3 3 4 5 5 6

// 1
// 2 3
// 3
 

// 2
// 2 3
// 3

// 2
// 3 3
// 4

// 3
// 3 4
// 5

// 3
// 4 5
// 5

// 4
// 5 5
// 6

