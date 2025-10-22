bool cmp(vector<int>&a , vector<int>&b){
    // ascending by first start 
    return a[0]<b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp);
        int start = v[0][0];
        int end = v[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<v.size();i++){
            int next_start = v[i][0];
            int next_end = v[i][1];
            if(next_start<=end){
                start = min(start,next_start);
                end = max(end , next_end);       
            }
            else{
                vector<int>temp;
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
                start = v[i][0];
                end = v[i][1];
            }
        }
        ans.push_back({start, end});
        return ans ;
    }
};