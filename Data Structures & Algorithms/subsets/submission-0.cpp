#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res; 
    void backtrack(vector<int>& nums, int i, vector<int>& curr) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);      
        backtrack(nums, i + 1, curr);   
        curr.pop_back();        
        backtrack(nums, i + 1, curr);   
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        backtrack(nums, 0, curr); 
        return res;
    }
};