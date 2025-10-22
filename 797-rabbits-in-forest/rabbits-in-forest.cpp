class Solution {
public:
    int numRabbits(vector<int>& arr) {
        /*
        * Space Complexity :- O(n)
        * Time Complexity :- O(n)
        */
        unordered_map<int,int>mp;
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i]+1)==mp.end()){
                // not present
                ans = ans + arr[i]+1;
            }
            mp[arr[i]+1]++;
            int val = mp[arr[i]+1];
            int key = arr[i]+1;
            if(key==val){
                mp.erase(key);
            }
        }
        return ans;
    }
};