#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (abs(target) > sum) return 0;
        if ((target + sum) % 2 != 0) return 0;
        int bagSize = (target + sum) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1; 
        for (int num : nums) {
            for (int j = bagSize; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[bagSize];
    }
};