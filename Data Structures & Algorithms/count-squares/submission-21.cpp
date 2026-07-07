#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

class CountSquares {
private:
    int counts[1001][1001] = {0};
    unordered_map<int, vector<int>> x_to_y;

public:
    CountSquares() {
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        if (counts[x][y] == 0) {
            x_to_y[x].push_back(y);
        }
        counts[x][y]++;
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int total_squares = 0;
        if (x_to_y.find(px) == x_to_y.end()) return 0;
        for (int y : x_to_y[px]) {
            if (y == py) continue; 
            int side = abs(y - py);
            int rx = px + side;
            if (rx <= 1000) {
                total_squares += counts[px][y] * counts[rx][py] * counts[rx][y];
            }
            int lx = px - side;
            if (lx >= 0) {
                total_squares += counts[px][y] * counts[lx][py] * counts[lx][y];
            }
        }
        
        return total_squares;
    }
};