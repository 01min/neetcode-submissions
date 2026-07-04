class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int downTwo = 0;
        int downOne = 0;
        for (int i = 2; i <= n; ++i) {
            int currentCost = min(downOne + cost[i - 1], downTwo + cost[i - 2]);
            
            downTwo = downOne;
            downOne = currentCost;
        }
        
        return downOne;
    }
};