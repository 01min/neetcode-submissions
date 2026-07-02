class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxHeap;
        
        for (int i = 0; i < points.size(); ++i) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            
            maxHeap.push({dist, i});
            
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
    
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            int index = maxHeap.top().second;
            maxHeap.pop();
            result.push_back(points[index]);
        }
        
        return result;
    }
};