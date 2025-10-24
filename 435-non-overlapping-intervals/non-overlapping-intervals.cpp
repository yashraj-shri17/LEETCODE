bool cmp(vector<int>&a , vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int lastEle = intervals[0][1];
        int ans = 0;
        for(int i=1;i<intervals.size();i++){
            int comp_ele = intervals[i][0];
            if(comp_ele<lastEle){
                ans++;
            }
            else{
                lastEle = intervals[i][1];
            }
        }
        return ans ;
    }
};