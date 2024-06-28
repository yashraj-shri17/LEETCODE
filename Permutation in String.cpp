#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);
        int s1Length = s1.length();
        int s2Length = s2.length();
        
        if (s1Length > s2Length) 
            return false;
        
        for (char c : s1)
            s1Count[c - 'a']++;
        
        for (int i = 0; i < s1Length; i++) {
            s2Count[s2[i] - 'a']++;
        }
        
        for (int i = s1Length; i < s2Length; i++) {
            if (s1Count == s2Count)
                return true;
            s2Count[s2[i] - 'a']++;
            s2Count[s2[i - s1Length] - 'a']--;
        }
        
        if (s1Count == s2Count)
            return true;
        
        return false;
    }
};
