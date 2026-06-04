class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int>arr(26,0);
        for(int i = 0 ; i < s.length() ; i++){
            arr[s[i]-97]++;
            arr[t[i]-97]--;
        }
        for(auto x : arr){
            if(x!=0) return false;
        }
        return true;
    }
};