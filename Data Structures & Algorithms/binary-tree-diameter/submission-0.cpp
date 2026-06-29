/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int max_diameter = 0; 
    int checkDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftDepth = checkDepth(root->left);
        int rightDepth = checkDepth(root->right);
        max_diameter = max(max_diameter, leftDepth + rightDepth);
        return max(leftDepth, rightDepth) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        checkDepth(root); 
        return max_diameter; 
    }
};