class Solution {
public:
    int rob(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int rob1 = 0; 
        int rob2 = 0; 
        for (int num : nums) {
            int currentMax = max(rob2, rob1 + num);
            rob1 = rob2;
            rob2 = currentMax;
        }
        
        return rob2;
    }
};