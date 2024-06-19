class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            bool flag=true;
            for(int i = 0;i<n;i++){
                if(s[i]!=t[i]){
                    flag = false;
                    break;
                }
            }
            if(flag && n==m){
                return true;
            }
            else{
                return false;
            }
    }
};
