class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_set<string> hashMap = {"electronics", "grocery", "restaurant", "pharmacy"};
        vector<tuple<string, string, bool>> coupons;
        auto isAlnum = [](const string& s) {
            if (s.empty()) return false; // disallow empty codes
            for (char c : s) {
                char ch = (c == '_') ? 'a' : c;
                if (!isalnum(ch)) return false;
            }
            return true;
        };
        for (size_t i = 0; i < code.size(); ++i) {
            if (hashMap.count(businessLine[i]) && isActive[i] && isAlnum(code[i])) {
                coupons.emplace_back(businessLine[i], code[i], isActive[i]);
            }
        }
        sort(coupons.begin(), coupons.end());
        vector<string> result;
        for (const auto& tup : coupons) {
            result.push_back(get<1>(tup));
        }
        return result;
    }
};