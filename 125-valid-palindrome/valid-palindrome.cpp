class Solution {
public:
    bool isPalindrome(string s) {
        string is_pal = "";
        for(int i = 0 ; i < s.size() ; i++){
            if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)|| (s[i]>=48 && s[i]<=57)) is_pal+= tolower(s[i]);
        }
        string rev = "";
        for(int i = is_pal.size()-1 ; i>=0 ; i--) rev+=is_pal[i];
        // if(rev.size()==1) return false;
        return rev==is_pal;
    }
};