class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        
        // Initializing the base cases
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        
        // Fill the dp array using the recursive relation
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        // The number of ways to reach the n-th step
        return dp[n];
    }
};
