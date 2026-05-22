class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        int st = -1*n/2;
        if(abs(n)%2!=0){
            while(n--){
            ans.push_back(st);
            st++;
            }
        }
        else{
            ans.push_back(abs(st));
            while(n--){
                if(st!=0)ans.push_back(st);
                st++;
            }
        }
        return ans;
    }
};