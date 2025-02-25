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
    void lnr(TreeNode* root , vector<int>&ans){
        if(root==nullptr) return ;
        ans.push_back(root->val);
        lnr(root->left,ans);
        lnr( root->right,ans);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        lnr(root,ans);

        return ans;
    }
};