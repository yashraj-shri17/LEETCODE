class Solution {
private:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
public:
    int largestPrime(int n) {
        if (n < 2) return 0;
        int sum = 0 , ans = 0;
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) {
                sum += i;
                if (sum <= n && isPrime(sum)) {
                    ans = sum;
                } else if (sum > n) {
                    return ans;
                }
            }
        }
        return ans;
    }
};