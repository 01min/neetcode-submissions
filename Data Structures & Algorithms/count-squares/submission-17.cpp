#include <cstring> 
class CountSquares {
private:
    int counts[1001][1001];
    vector<pair<int, int>> unique_points;

public:
    CountSquares() {
        memset(counts, 0, sizeof(counts));
    }
    
    void add(vector<int> point) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int x = point[0];
        int y = point[1];
        if (counts[x][y] == 0) {
            unique_points.push_back({x, y});
        }
        counts[x][y]++;
    }
    
    int count(vector<int> point) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int px = point[0];
        int py = point[1];
        int total_squares = 0;
        for (const auto& p : unique_points) {
            int x = p.first;
            int y = p.second;
            if (x == px || y == py) continue;
            if (abs(x - px) != abs(y - py)) continue;
            total_squares += counts[x][y] * counts[px][y] * counts[x][py];
        }
        
        return total_squares;
    }
};