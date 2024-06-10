class Solution {
public:
    int scoreOfString(string s) {
        int n=s.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            v.push_back((int)s[i]);
        }
        int sum=0;
        for(int i=0;i<n-1;i++){
            sum+=abs(v[i]-v[i+1]);
        }
        return sum;
    }
};
