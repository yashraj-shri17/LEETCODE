class Solution {
public:
    int rec(vector<int>& nums , int i){
        if(i==nums.size()-1) return nums[i];
        if(i==nums.size()-2) return max(nums[i] , nums[i+1]);
        return max(nums[i] + rec(nums , i+2) , rec(nums , i+1));
    }
    vector<int>dp;
    int ftd(vector<int>& nums , int i){
        if(i==nums.size()-1) return nums[i];
        if(i==nums.size()-2) return max(nums[i] , nums[i+1]);
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(nums[i] + ftd(nums , i+2) , ftd(nums , i+1));
    }

    int fbu(vector<int>& nums){
        int n = nums.size();
        if(n==1) return nums[n-1];
        if(n==2) return max(nums[n-2] , nums[n-2+1]);
        dp.clear();
        dp.resize(105,-1);
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-2] , nums[n-2+1]);
        for(int i = n-3 ; i>=0 ; i--){
            dp[i] = max(nums[i] + dp[i+2] , dp[i+1]);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(110,-1);
        //return rec(nums, 0);
        return fbu(nums);
    }
};