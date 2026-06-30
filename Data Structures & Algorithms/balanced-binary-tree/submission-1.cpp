class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        
        if (abs(heightoftree(root->left) - heightoftree(root->right)) >= 2) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int heightoftree(TreeNode* node) {
        if (node == NULL) return 0;
        if (node->left == NULL && node->right == NULL) return 1;
        return max(heightoftree(node->left), heightoftree(node->right)) + 1;
    }
};