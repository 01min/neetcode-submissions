class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_count = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    fresh_count++;
                }
            }
        }
        if (fresh_count == 0) return 0;
        
        int minutes = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty() && fresh_count > 0) {
            int layer_size = q.size();
            minutes++; 
            for (int i = 0; i < layer_size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                
                for (auto [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; 
                        fresh_count--;   
                        q.push({nr, nc}); 
                    }
                }
            }
        }
        return fresh_count == 0 ? minutes : -1;
    }
};