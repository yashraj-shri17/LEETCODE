class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt_zero = 0;
        int product = 1;
        vector<int>ans(nums.size());
        for(auto x : nums){
            if(x==0) cnt_zero++;
            if(x!=0) product = x*product;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(cnt_zero==0){
                ans[i] = product/nums[i];
            }
            else if(cnt_zero==1){
                if(nums[i]!=0) ans[i] = 0;
                else ans[i] = product;
            }
            else{
                ans[i] = 0;
            }
        }
        return ans;
    }
};