
class Solution {
public:
    int solve(TreeNode * root, int &maxi){
        if(root==nullptr) return 0;

        int lft = solve(root->left, maxi);
        int rght = solve(root->right,maxi);

        maxi=max(maxi , lft+rght);

        return 1+max(lft,rght);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        solve(root, maxi);
        return maxi;
    }
};