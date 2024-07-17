#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int p1 = m - 1; // Pointer to the end of the m elements in nums1
        int p2 = n - 1; // Pointer to the end of nums2
        int p = m + n - 1; // Pointer to the end of nums1's total length

        // Iterate from the end of nums1 array
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        // If there are remaining elements in nums2
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p--;
            p2--;
        }
    }
};
