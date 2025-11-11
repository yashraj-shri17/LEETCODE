class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) mp[nums[i]].push_back(i);
        int mini = INT_MAX;
        for (auto x : mp) { 
            vector<int> ele_vector = x.second;
            if (ele_vector.size() >= 3) {
                for (int i = 0; i <= ele_vector.size() - 3; i++) { 
                    int val = abs(ele_vector[i] - ele_vector[i + 1]) 
                            + abs(ele_vector[i + 1] - ele_vector[i + 2]) 
                            + abs(ele_vector[i + 2] - ele_vector[i]);
                    mini = min(mini, val);
                }
            }
        }
        if (mini == INT_MAX) return -1;
        return mini;
    }
};
