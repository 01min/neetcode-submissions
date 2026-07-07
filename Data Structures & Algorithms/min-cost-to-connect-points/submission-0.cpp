#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return 0;
        vector<int> min_dist(n, INT_MAX);
        vector<bool> in_mst(n, false);
        
        int min_cost = 0;
        int edges_connected = 0;
        int curr_node = 0;
        min_dist[curr_node] = 0;
        while (edges_connected < n) {
            in_mst[curr_node] = true;
            min_cost += min_dist[curr_node];
            edges_connected++;
            
            if (edges_connected == n) break;
            
            int next_node = -1;
            int next_min_edge = INT_MAX;
            for (int v = 0; v < n; ++v) {
                if (!in_mst[v]) {
                    int dist = abs(points[curr_node][0] - points[v][0]) + 
                               abs(points[curr_node][1] - points[v][1]);
                    
                    if (dist < min_dist[v]) {
                        min_dist[v] = dist;
                    }
                    if (min_dist[v] < next_min_edge) {
                        next_min_edge = min_dist[v];
                        next_node = v;
                    }
                }
            }
            curr_node = next_node;
        }
        
        return min_cost;
    }
};