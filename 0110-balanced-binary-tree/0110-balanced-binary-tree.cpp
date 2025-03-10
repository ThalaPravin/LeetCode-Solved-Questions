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
    int height(TreeNode* root, int h){
        if(root==nullptr) return h;

        int a=height(root->left,h+1);
        int b=height (root->right, h+1);

        return max(a,b);

    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;

        int l=height(root->left,0);
        int r=height(root->right,0);

        if(abs(l-r)>1) return false;

        bool lft=isBalanced(root->left);
        bool rht=isBalanced(root->right);

        if(!lft || !rht) return false;

        return true;
    }
};