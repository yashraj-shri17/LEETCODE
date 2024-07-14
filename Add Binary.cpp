#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int total_sum = carry;
            if (i >= 0) {
                total_sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                total_sum += b[j] - '0';
                j--;
            }
            
            result += (total_sum % 2) + '0';
            carry = total_sum / 2;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};