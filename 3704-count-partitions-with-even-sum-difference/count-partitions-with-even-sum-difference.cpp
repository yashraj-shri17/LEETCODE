class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int tsum  = 0 ;
        int cnt = 0;
        for(auto x : nums) tsum+=x; // tsum-->>36
        int leftsum = 0 , rightsum = 0;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            leftsum+=nums[i]; // leftsum->10-->20
            rightsum = tsum - leftsum; // rightsum-->26-->16
            if(abs(leftsum-rightsum)%2==0){
                cout<<abs(leftsum-rightsum)<<" ";
                cnt++;
            } //cnt-->1
        }
        return cnt;
    }
};