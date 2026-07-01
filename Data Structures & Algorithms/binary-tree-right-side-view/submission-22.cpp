class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> v;
        leveltravel(root, 0, v);
        vector<int> ans;
        for (int i = 0; i < v.size(); i++) {
            if (!v[i].empty()) {
                ans.push_back(v[i].back()); 
            }
        }
        return ans;
    }

private:
    void leveltravel(TreeNode* root, int lev, vector<vector<int>>& v) {
        if (root == nullptr) return;

        if (v.size() <= lev) {
            v.push_back({});
        }
        v[lev].push_back(root->val);

        leveltravel(root->left, lev + 1, v);
        leveltravel(root->right, lev + 1, v);
    }
};