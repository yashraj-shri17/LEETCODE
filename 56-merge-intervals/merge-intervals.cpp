bool cmp(vector<int>&a , vector<int>&b){
    // ascending by first start 
    return a[0]<b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp);
        int final_start = v[0][0];
        int final_end = v[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<v.size();i++){
            int next_start = v[i][0];
            int next_end = v[i][1];
            if(next_start<=final_end){
                final_start = min(final_start,next_start);
                final_end = max(final_end , next_end);       
            }
            else{
                vector<int>temp;
                temp.push_back(final_start);
                temp.push_back(final_end);
                ans.push_back(temp);
                final_start = v[i][0];
                final_end = v[i][1];
            }
        }
        ans.push_back({final_start, final_end});
        return ans ;
    }
};