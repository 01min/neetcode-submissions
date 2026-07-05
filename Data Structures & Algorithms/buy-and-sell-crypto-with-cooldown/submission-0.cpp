class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int held = -prices[0]; 
        int sold = 0;         
        int cooldown = 0;     
        
        for (size_t i = 1; i < prices.size(); ++i) {
            int price = prices[i];
            int prev_held = held;
            int prev_sold = sold;
            int prev_cooldown = cooldown;
            held = max(prev_held, prev_cooldown - price);
            sold = prev_held + price;
            cooldown = max(prev_cooldown, prev_sold);
        }
        return max(sold, cooldown);
    }
};