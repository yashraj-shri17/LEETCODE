class Solution {
public:
    #define ll long long

    long long binpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }

    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        for (int i = 0; i <= 31; i++) {
            ll ans = binpow(2, i);
            if (ans == n) return true;
            if (ans > n) break; // optimization
        }
        return false;
    }
};
