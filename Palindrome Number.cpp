class Solution {
public:
    bool isPalindrome(int x) {
        // Handle negative numbers and numbers ending with 0
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // For even-length palindrome numbers, reversed will be one digit longer than x
        // For odd-length palindrome numbers, reversed will be the same length as x
        return x == reversed || x == reversed / 10;
    }
};

