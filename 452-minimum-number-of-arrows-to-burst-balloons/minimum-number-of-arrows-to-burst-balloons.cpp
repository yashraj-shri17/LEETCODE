bool cmp(vector<int>&a , vector<int>&b){
    return a[1] < b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int comp_end = points[0][1];
        int cnt = 0;
        for(int i=1 ; i < points.size() ; i++){
            int check_start = points[i][0];
            // overlapping exist
            if(check_start <= comp_end){
                cnt++;
            }
            else{
                comp_end = points[i][1];
            }
        }
        return points.size()-cnt;
    }
};