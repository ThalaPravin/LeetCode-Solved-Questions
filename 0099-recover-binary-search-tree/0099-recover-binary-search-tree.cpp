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
    void solve(TreeNode * root, vector<int>&io, int &cnt){
        if(root==nullptr) return;
        solve(root->left, io, cnt);
        root->val=io[cnt++];
        solve(root->right, io, cnt);
    }

    void inorder(TreeNode * root, vector<int>&io){
        if(root==nullptr) return;
        inorder(root->left, io);
        io.push_back(root->val);
        inorder(root->right, io);
    }
    void recoverTree(TreeNode* root) {
        vector<int>io;
        inorder(root,io);
        sort(io.begin(), io.end());

        int cnt=0;

         solve(root,io,cnt);
        return;
    }
};