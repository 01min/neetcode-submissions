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
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root,ans);
        return ans[k-1];
    }
private:
    void inorder(TreeNode* root,vector<int>&v){
        if(root==NULL)return;
        if(root->left!=NULL)inorder(root->left,v);
        v.push_back(root->val);
        if(root->right!=NULL)inorder(root->right,v);
    }
};
