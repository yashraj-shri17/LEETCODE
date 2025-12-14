class Solution {
public:
    string reverseWords(string s) {
        int feven = 0;
        int i = 0;
        string ans = "";

        while(i<s.size() && s[i]!=' '){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                feven++;
            }
            ans+=s[i];
            i++;
        }

        if(i < s.size()) ans += " ";
        if(i+1 < s.size()-1) i++;

        while(i<s.size()){
            int temp = 0;
            string temps = "";
            while(i<s.size() && s[i]!=' '){
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                    temp++;
                }
                temps += s[i];
                i++;
            }

            if(temp == feven){
                reverse(temps.begin(), temps.end());
            }

            for(auto x : temps) ans += x;
            if(i < s.size()) ans += " ";
            i++;
        }

        string finalans = "";
        for(int i = 0; i < ans.size(); i++){
            if(i > 0 && ans[i]==' ' && ans[i-1]==' ') continue;
            finalans += ans[i];
        }

        if(!finalans.empty() && finalans.back()==' ')
            finalans.pop_back();

        return finalans;
    }
};
