class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void f(vector<int>& candidates, int target, int start){
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        if(start == candidates.size()) return;
        for(int i = start; i < candidates.size(); ++i){
            if(i > start && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            cur.push_back(candidates[i]);
            f(candidates, target - candidates[i], i + 1);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        f(candidates, target, 0);
        return ans;
    }
};
