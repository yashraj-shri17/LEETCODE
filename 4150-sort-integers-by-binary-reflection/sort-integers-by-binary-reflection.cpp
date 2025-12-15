class Solution {
public:
    priority_queue<pair<int,int>>pq;
    vector<int> sortByReflection(vector<int>& nums) {
        for(auto x : nums){
            string bin = bitset<32>(x).to_string();
            bin = bin.substr(bin.find('1'));
            reverse(bin.begin(), bin.end());
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