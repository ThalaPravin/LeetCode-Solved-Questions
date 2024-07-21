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
    bool isBalanced(TreeNode* root) {
       if(root==nullptr) return true;

       int l=solve(root->left,0);
       int r= solve(root->right, 0);

       if(abs(l-r)>1) return false;

       int ls=isBalanced(root->left);
       int rs=isBalanced(root->right);

       if(!ls || !rs) return false;

       return true;
    }
};