class Solution {
public:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node], parent);
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int rootU = findParent(u, parent);
            int rootV = findParent(v, parent);
            if (rootU == rootV) {
                return false;
            }
            parent[rootU] = rootV;
        }
        return true;
    }
};