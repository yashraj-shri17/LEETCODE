class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int i = 0 , minsum = 0;
        while(i<k){
            minsum += nums[i];
            i++;
        }
        i = nums.size()-1 ; 
        int maxsum = 0;
        while(k--){
            maxsum += nums[i];
            i--;
        }
        cout<<maxsum<<" ";
        return maxsum - minsum;
    }
};