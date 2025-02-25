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
    // void solve(TreeNode* root, vector<vector<int>>&ans){
    //     if(root==nullptr ) return ;
    //     ans.push_back(ans->val);

    // }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr) return ans;
        // solve(root, ans);

        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
          int size= q.size();
          vector<int>level;

          for(int i=0; i<size; i++){
            TreeNode * temp=q.front();
            q.pop();

            level.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);

          }

          ans.push_back(level);
        }

        return ans;
    }
};