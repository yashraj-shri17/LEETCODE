class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int tsum  = 0 , cnt = 0;
        for(auto x : nums) tsum+=x;
        int leftsum = 0 , rightsum = 0;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            leftsum+=nums[i]; 
            rightsum = tsum - leftsum; 
            if(abs(leftsum-rightsum)%2==0) cnt++;
        }
        return cnt;
    }
};