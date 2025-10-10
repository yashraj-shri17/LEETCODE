class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        for (int r = 0; r < k; ++r) {
            if (r >= n) break;
            int last = r + ((n - 1 - r) / k) * k;
            int sum = 0;
            int best = INT_MIN;
            for (int i = last; i >= r; i -= k) {
                sum += energy[i];
                if (sum > best) best = sum;
            }
            if (best > ans) ans = best;
        }
        return ans;
    }
};
