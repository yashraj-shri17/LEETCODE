class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>max_arr(n);
        int maxi = prices[n-1];
        max_arr[n-1] = INT_MIN;
        for(int i = n-2 ; i >= 0 ; i--){
            max_arr[i] = maxi;
            maxi = max(maxi , prices[i]);
        }
        int global_max = INT_MIN;
        maxi = INT_MIN;
        for(int i = 0 ; i < n-1 ; i++){
            global_max = max(global_max , max_arr[i]-prices[i]);
        }
        if(global_max<0) return 0;
        return global_max;
    }
};