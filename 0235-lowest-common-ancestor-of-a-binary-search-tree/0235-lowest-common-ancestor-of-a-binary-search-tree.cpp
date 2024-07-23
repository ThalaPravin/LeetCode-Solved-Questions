/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode * solve(TreeNode * root, TreeNode * p, TreeNode * q){
        if(root==nullptr) return root;
        
         if(root==p) return p;
         else if(root==q) return q;

        
        TreeNode * l=solve(root->left, p,q);
        TreeNode * r= solve(root->right, p,q);

        if(l && r) return root;

        else if(l ) return l;
        else return  r;

        // return root;
   }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * ans= solve(root, p, q);
        return ans;
    }
};