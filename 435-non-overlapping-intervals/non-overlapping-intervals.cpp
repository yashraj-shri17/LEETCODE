bool cmp(vector<int>&a , vector<int>&b){
    return a[0] < b[0];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> temp;
        int check_start = intervals[0][0];
        int check_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start < check_end) {
                check_end = min(check_end, end);
            } else {
                temp.push_back({check_start, check_end});
                check_start = start;
                check_end = end;
            }
        }
        temp.push_back({check_start, check_end});
        return intervals.size() - temp.size();
    }
};
