#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, int target, int i, vector<int>& curr) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0 || i == nums.size()) {
            return;
        }
        curr.push_back(nums[i]);
        backtrack(nums, target - nums[i], i, curr); 
        curr.pop_back();
        backtrack(nums, target, i + 1, curr);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        backtrack(nums, target, 0, curr);
        return res;
    }
};