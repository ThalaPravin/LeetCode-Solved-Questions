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
    int solve(TreeNode * root, int h){
        if(root==nullptr) return h;
        int a=solve(root->left, h+1);
        int b=solve(root->right, h+1);
        return max(a,b);
        
    }
    int maxDepth(TreeNode* root) {
        int ans=0;
       ans= solve(root,0);
        return ans;
    }
};