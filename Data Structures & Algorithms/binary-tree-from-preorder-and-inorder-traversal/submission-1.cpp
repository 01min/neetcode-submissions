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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if (preorder.empty() || inorder.empty()) return nullptr;

        int root_val = preorder[0];
        TreeNode* root = new TreeNode(root_val);

        int root_idx = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root_val) {
                root_idx = i;
                break;
            }
        }
        
        vector<int> left_inorder(inorder.begin(), inorder.begin() + root_idx);
        vector<int> right_inorder(inorder.begin() + root_idx + 1, inorder.end());

        int left_size = left_inorder.size();
        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + left_size);
        vector<int> right_preorder(preorder.begin() + 1 + left_size, preorder.end());

        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);

        return root;
    }
};