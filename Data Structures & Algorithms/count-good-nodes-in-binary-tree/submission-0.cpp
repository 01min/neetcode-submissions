/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode* root, int max_val) {
        if (root == nullptr) return 0;
        int current_good = 0;
        if (root->val >= max_val) {
            current_good = 1;         
            max_val = root->val;    
        }
        int left_good = dfs(root->left, max_val);
        int right_good = dfs(root->right, max_val);

        return current_good + left_good + right_good;
    }
};