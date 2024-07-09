#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0);

        // Preprocess to create the prefix array
        for (int i = 1; i < n; ++i) {
            if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 1) || 
                (nums[i - 1] % 2 == 1 && nums[i] % 2 == 0)) {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1];
            }
        }

        vector<bool> results;

        // Process each query
        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];
            int length = end - start;

            // If the length is 1 or less, it's trivially special
            if (length < 1) {
                results.push_back(true);
                continue;
            }

            // Check the number of alternating pairs in the range
            int alternatingPairs = prefix[end] - prefix[start];
            results.push_back(alternatingPairs == length);
        }

        return results;
    }
};
