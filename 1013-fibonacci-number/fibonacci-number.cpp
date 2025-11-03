class Solution {
public:
    vector<int>dp;
    int helper(int n){
        if(n==0 || n==1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = helper(n-1) + helper(n-2);
    }
    int fib(int n) {
        dp.clear();
        dp.resize(1e5,-1);
        int ans = helper(n);
        return ans;
    }
};