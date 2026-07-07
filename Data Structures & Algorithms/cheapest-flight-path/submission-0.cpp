#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        vector<int> prices(n, INF);
        prices[src] = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;
        while (!q.empty() && stops <= k) {
            vector<int> temp_prices = prices;
            
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [curr, curr_price] = q.front();
                q.pop();
                for (const auto& next_flight : adj[curr]) {
                    int next_node = next_flight.first;
                    int price = next_flight.second;
                    if (curr_price + price < temp_prices[next_node]) {
                        temp_prices[next_node] = curr_price + price;
                        q.push({next_node, temp_prices[next_node]});
                    }
                }
            }
            prices = temp_prices;
            stops++;
        }
        
        return prices[dst] == INF ? -1 : prices[dst];
    }
};