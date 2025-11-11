class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]].push_back(i); // index
        }
        int mini = INT_MAX;
        for(auto x : mp){
            int ele = x.first;
            vector<int> ele_vector = x.second;
            if(ele_vector.size()>=3){
                int temp = ele_vector.size() - 3;
                for(int i = 0 ; i <= temp ; i++){
                    int first = ele_vector[i];
                    int second = ele_vector[i+1];
                    int third = ele_vector[i+2];
                    int ans = abs(first-second) + abs(second-third) + abs(third-first);
                    mini = min(mini , ans);
                }       
            }
        }
        if(mini ==INT_MAX) return -1;
        return mini;
    }
};