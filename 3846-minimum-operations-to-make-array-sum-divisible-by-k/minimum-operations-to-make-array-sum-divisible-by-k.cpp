class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       int sum_get = 0;
       for(auto x : nums) sum_get+=x;
       return sum_get%k; 
    }
};