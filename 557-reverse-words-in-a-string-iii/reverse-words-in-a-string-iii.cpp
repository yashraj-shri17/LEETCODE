class Solution {
public:
    string reverseWords(string s) {
        int n = s.size() , i = 0;
        string final_ans = "";
        while (i < n) {
            string temp = "";
            while (i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            reverse(temp.begin(), temp.end());
            final_ans += temp;
            if (i < n) final_ans += " ";
            i++;
        }
        return final_ans;
    }
};
