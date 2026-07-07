class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global_max = nums[0];
        int current_sum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            current_sum = max(nums[i], current_sum + nums[i]);
            global_max = max(global_max, current_sum);
        }
        
        return global_max;
    }
};