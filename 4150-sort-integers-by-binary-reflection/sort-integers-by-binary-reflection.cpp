class Solution {
public:
    priority_queue<pair<int,int>>pq;
    vector<int> sortByReflection(vector<int>& nums) {
        for(auto x : nums){
            string bin = bitset<32>(x).to_string();
            bin = bin.substr(bin.find('1'));   // "1101"

            // step 2: reverse binary
            reverse(bin.begin(), bin.end());   // "1011"

            // step 3: binary -> decimal
            int ans = stoi(bin, nullptr, 2);
            pq.push({ans , x});
        }
        vector<int>Ans;
        while(pq.size()>0){
            auto x = pq.top();
            Ans.push_back(x.second);
            pq.pop();
        }
        reverse(Ans.begin(),Ans.end());
        return Ans;
    }
};