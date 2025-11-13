class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;

        int start = nums[0]; // start of current range

        for(int i = 1; i < nums.size(); i++){
            // if not consecutive
            if(nums[i] != nums[i-1] + 1){
                if(start == nums[i-1]) 
                    res.push_back(to_string(start));
                else 
                    res.push_back(to_string(start) + "->" + to_string(nums[i-1]));
                start = nums[i]; // reset start for next range
            }
        }

        // handle last range
        if(start == nums.back())
            res.push_back(to_string(start));
        else
            res.push_back(to_string(start) + "->" + to_string(nums.back()));

        return res;
    }
};
