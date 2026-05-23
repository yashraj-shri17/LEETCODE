class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     unordered_map<int,int>mp;
     for(int i = 0 ; i < nums.size() ; i++){
        mp[nums[i]] = i;
     }
     for(int i = 0 ; i < nums.size() ; i++){
        int to_find = target - nums[i];
        if(mp.find(to_find)!=mp.end() && i!=mp[to_find]){
            return {i,mp[to_find]};
        }
     }
     return {-1,-1};
    }
};