class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
         int cnt = 0;
        unordered_set<string>s;
        for(int i = 0 ;i<n;i++){
             s.insert(words[i]);
        }
        for(int i=0;i<n;i++){
           string rev  = words[i];
            reverse(rev.begin(),rev.end());
            if(rev==words[i]) continue;
            if(s.find(rev)!=s.end()){ 
                cnt++;
                s.erase(words[i]);
            }
        }
        return cnt;
    }
};