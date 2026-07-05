class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        vector<int> sub;
        
        for (int num : nums) {
            auto it = lower_bound(sub.begin(), sub.end(), num);
            if (it == sub.end()) {
                sub.push_back(num);
            } else {
                *it = num;
            }
        }
        return sub.size();
    }
};