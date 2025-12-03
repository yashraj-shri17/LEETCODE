class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int tsum = 0;
        int n = nums.size();
        for(auto x : nums) tsum+=x;
        return (n*(n+1))/2 - tsum;
    }
};