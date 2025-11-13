class Solution {
public:
    int addDigits(int num) {
        while(num >= 10){ // repeat until single digit
            int ans = 0;
            int temp = num;
            while(temp > 0){
                ans += temp % 10;
                temp /= 10;
            }
            num = ans; // replace num with the sum
        }
        return num;
    }
};
