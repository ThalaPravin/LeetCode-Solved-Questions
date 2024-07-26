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
    vector<pair<int, TreeNode * >> ancestors;
    vector<int>ans;

    bool findancestor(TreeNode * root, TreeNode * target){
        if(!root) return false;
        if(root==target){
            ancestors.push_back({-1,root});
            return true;
        }

        bool right= findancestor(root->right, target);
        bool left= findancestor(root->left, target);

        if(left) ancestors.push_back({1,root});
        if(right) ancestors.push_back({0,root});

        return right ||left;
    }

    void findans(TreeNode * root, int k, int depth, int child){
        if(!root) return;

        if(k==depth){
            ans.push_back(root->val);
            return;
        }

        if(depth==0 && child ==1) findans(root->right, k, depth+1, child);
        else if(depth==0 && child==0) findans(root->left,k, depth+1, child);
        else{
            findans(root->left,k, depth+1, child);
            findans(root->right, k, depth+1, child);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         findancestor(root,target);
        for(auto [child,ptr]: ancestors){
            findans(ptr,k,0,child);
            k--;
        }
        return ans;
    }
};