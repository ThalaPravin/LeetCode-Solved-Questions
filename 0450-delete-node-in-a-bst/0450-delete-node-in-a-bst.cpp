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
    TreeNode * findMinn(TreeNode * root){
        if(!root) return nullptr;
        if(root->left==nullptr) return root;
        return findMinn(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
       
        if(root->val<key) root->right=deleteNode(root->right, key);
        else if(root->val>key)  root->left=deleteNode(root->left, key);
        else{
                if(root->left==nullptr) return root->right;
        if(root->right==nullptr) return root->left;
        
        TreeNode * minnd=findMinn(root->right);
        root->val=minnd->val;
        root->right=deleteNode(root->right,minnd->val);
        }
        
        return root;
    }
};