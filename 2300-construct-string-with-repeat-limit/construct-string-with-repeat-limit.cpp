class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;
        for(char c : s) mp[c]++;

        // sort by lexicographically largest char
        priority_queue<pair<char,int>> pq;
        for(auto x : mp) pq.push({x.first, x.second});

        string ans = "";
        while(!pq.empty()) {
            auto largest = pq.top();
            pq.pop();
            char ch = largest.first;
            int freq = largest.second;

            int use = min(freq, repeatLimit);
            ans.append(use, ch);
            freq -= use;

            if(freq > 0) {
                if(pq.empty()) break; // no other char left to break repetition

                auto second = pq.top(); pq.pop();
                ans.push_back(second.first);
                second.second--;

                // push remaining back
                if(second.second > 0) pq.push(second);
                pq.push({ch, freq});
            }
        }
        return ans;
    }
};
