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
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(110,-1);
        //return rec(nums, 0);
        return ftd(nums , 0);
    }
};