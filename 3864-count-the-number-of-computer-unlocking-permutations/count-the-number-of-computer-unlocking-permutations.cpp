class Solution {
public:
    static const int MOD = 1000000007;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size() , fi = complexity[0];
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= fi) return 0;
        }
        long long truth = 1;
        for (int i = 2; i < n; i++) truth = (truth * i) % MOD;
        return (int)truth;
    }
};