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
    bool solve(TreeNode* p, TreeNode* q){
        if(p== nullptr && q!=nullptr) return false;
        if(p!=nullptr && q==nullptr) return false;
        if(p==nullptr && q== nullptr) return true;

        if(p->val != q->val) return false;

        bool l= solve(p->left, q->left);
        bool r= solve(p->right, q->right);

        return l&&r;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};