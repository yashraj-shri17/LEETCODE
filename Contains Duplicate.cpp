class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        bool flag = true;
        for(int  i = 0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                flag = false;
                break;
            }
        }
        if(flag){
            return false;
        }
        else{
            return true;
        }

    }
};
